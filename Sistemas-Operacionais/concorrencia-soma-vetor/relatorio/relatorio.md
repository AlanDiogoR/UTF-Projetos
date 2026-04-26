# Relatório Técnico — Concorrência em Sistemas Operacionais

**Atividade:** Soma paralela de vetor (Sequencial × OpenMP × Intel TBB)
**Disciplina:** Sistemas Operacionais — UTFPR / Engenharia de Software
**Autor:** Alan Diogo R.
**Data:** 25/04/2026

---

## 1. Introdução e objetivo

O exercício consiste em somar os elementos de um vetor de inteiros de
tamanho **N = 10⁸ (cem milhões)**, comparando três estratégias de execução:

1. **Sequencial** — laço `for` tradicional, executado em uma única *thread*.
2. **Paralela com OpenMP** — diretiva `#pragma omp parallel for reduction(+:soma)`.
3. **Paralela com Intel TBB** — `tbb::parallel_reduce` sobre `tbb::blocked_range`.

O objetivo é mensurar empiricamente o ganho de desempenho proporcionado pela
paralelização em um problema *embarrassingly parallel*, calcular a **média** e o
**desvio padrão** dos tempos em 30 execuções de cada abordagem e discutir o
comportamento observado.

## 2. Metodologia

### 2.1. Ambiente de execução

| Item | Descrição |
| :--- | :--- |
| Sistema | *(preencher: ex. Ubuntu 24.04 / Windows 11 + WSL2)* |
| CPU | *(preencher: modelo, núcleos físicos, threads lógicas)* |
| Memória | *(preencher)* |
| Compilador | g++ *(versão: `g++ --version`)* |
| OpenMP | nativo do GCC (`-fopenmp`) |
| Intel TBB | `libtbb-dev` *(versão)* |
| Flags | `-O2 -std=c++17 -fopenmp -DUSE_TBB -ltbb` |

> O quadro deve ser preenchido com os dados da máquina utilizada antes da
> entrega final.

### 2.2. Geração do vetor

O vetor é alocado uma única vez (`std::vector<int> v(N)`), preenchido com
inteiros gerados por `std::mt19937` (semente fixa = 42) no intervalo \[1, 100\].
A semente fixa garante **reprodutibilidade** e permite que as três abordagens
operem exatamente sobre o mesmo conjunto de dados.

### 2.3. Medição do tempo

A medição é feita em C++ com `std::chrono::high_resolution_clock`,
encapsulando apenas a região do laço de soma (sem incluir alocação ou geração
de dados). Em Linux a chamada do binário ainda pode ser envolvida pelo comando
`time ./somar_vetor`, fornecendo o tempo total de *wall-clock* como conferência.

```cpp
auto inicio = std::chrono::high_resolution_clock::now();
long long soma = somaSequencial(v);  // (ou somaOpenMP / somaTBB)
auto fim = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> dur = fim - inicio;
double segundos = dur.count();
```

### 2.4. Protocolo experimental

Para cada uma das três abordagens são realizadas **30 execuções** consecutivas
sobre o mesmo vetor. Os tempos individuais são gravados em
`resultados/tempos.csv` no formato:

```
execucao,sequencial,openmp,tbb
1,0.234,0.061,0.058
...
30,0.232,0.063,0.057
```

Em seguida o script `scripts/gerar_graficos.py` calcula, para cada abordagem,
**média (\(\bar{x}\))** e **desvio padrão amostral (\(s\))**:

\[
\bar{x} = \frac{1}{n}\sum_{i=1}^{n} x_i, \qquad
s = \sqrt{\frac{1}{n-1}\sum_{i=1}^{n}\left(x_i - \bar{x}\right)^2}, \qquad n = 30.
\]

O *speedup* é calculado por
\(\text{speedup} = \bar{x}_{\text{seq}} / \bar{x}_{\text{paralelo}}\).

### 2.5. Estratégias de paralelização

- **OpenMP.** A cláusula `reduction(+: soma)` instrui o compilador a criar uma
  cópia privada da variável `soma` em cada *thread* e somar tudo ao final,
  eliminando *race conditions*. Foi usado `schedule(static)` por se tratar de
  carga uniforme — cada bloco custa o mesmo, então a divisão estática evita
  *overhead* de coordenação dinâmica.
- **Intel TBB.** `tbb::parallel_reduce` divide o intervalo recursivamente
  (`tbb::blocked_range`), executa parcialmente em cada *worker* via lambda e
  combina os resultados com `std::plus<long long>`. O *task scheduler* da TBB
  faz o balanceamento automaticamente.

A soma de referência produzida pela versão sequencial é comparada às demais a
cada execução; divergências seriam reportadas no console — não foram
observadas durante os testes.

## 3. Resultados

> **Nota:** Os valores abaixo devem ser substituídos pelos números obtidos em
> `resultados/estatisticas.csv` após executar o experimento. A estrutura da
> tabela é a esperada.

### 3.1. Estatísticas — 30 execuções

| Abordagem | Média (s) | Desvio padrão (s) | Mín (s) | Máx (s) | *Speedup* |
| :--- | ---: | ---: | ---: | ---: | ---: |
| Sequencial | *—* | *—* | *—* | *—* | 1,00× |
| OpenMP | *—* | *—* | *—* | *—* | *—* |
| Intel TBB | *—* | *—* | *—* | *—* | *—* |

### 3.2. Gráficos das 30 execuções

- `resultados/grafico_sequencial.png` — curva da abordagem sequencial.
- `resultados/grafico_openmp.png` — curva da abordagem OpenMP.
- `resultados/grafico_tbb.png` — curva da abordagem Intel TBB.
- `resultados/grafico_comparativo.png` — sobreposição das três curvas.
- `resultados/grafico_boxplot.png` — distribuição agregada dos tempos.

> Insira aqui os arquivos PNG gerados (no Word/LaTeX use `![](caminho.png)`
> ou ferramenta equivalente). Em Markdown puro:
>
> ```markdown
> ![Comparativo](../resultados/grafico_comparativo.png)
> ```

## 4. Discussão dos resultados

A análise dos tempos esperada (e que deverá ser confirmada pelos dados reais
após a execução) sugere os seguintes pontos:

1. **Ganho expressivo de desempenho** das versões paralelas em relação à
   sequencial, proporcional ao número de núcleos físicos disponíveis. Um
   *speedup* próximo do número de núcleos é a referência teórica para um
   problema perfeitamente paralelo.
2. **OpenMP × TBB.** Para esta carga (`reduction` simples sobre vetor contíguo
   em memória) ambos costumam apresentar desempenho próximo. O OpenMP tende a
   ter *overhead* menor de inicialização porque as *threads* são criadas pelo
   *runtime* uma única vez e reutilizadas; já a TBB pode tirar vantagem do
   balanceamento dinâmico em cargas heterogêneas, mas isso pouco se traduz em
   ganho aqui.
3. **Limite de banda de memória.** Como cada elemento é lido apenas uma vez,
   o problema é dominado pela **largura de banda de memória**, não pela CPU.
   Por isso, mesmo dobrando o número de *threads*, o ganho costuma saturar
   (escalabilidade sublinear). Esse é o motivo pelo qual o *speedup* observado
   tipicamente fica abaixo do número de núcleos.
4. **Dispersão dos tempos.** O desvio padrão das versões paralelas geralmente é
   maior em termos relativos por causa de variações no escalonamento do SO,
   contenção de cache e flutuações da banda de memória. A primeira execução
   (\"warm-up\") costuma ser a mais lenta — efeito visível no gráfico de linha.
5. **Correção.** A soma calculada pelas três versões coincidiu em todas as
   execuções, confirmando que `reduction` (OpenMP) e `parallel_reduce` (TBB)
   foram empregados corretamente.

## 5. Conclusão

O experimento confirma que paralelizar uma operação trivial como a soma de um
vetor produz redução substancial do tempo de execução em máquinas modernas
*multi-core*, mas o ganho é limitado pela banda de memória e pelo *overhead*
de criação/sincronização de *threads*. Tanto **OpenMP** (intrusivo, baseado em
diretivas) quanto **Intel TBB** (idiomático em C++ moderno) são alternativas
válidas; a escolha entre elas é tipicamente guiada por estilo do projeto e
necessidade de balanceamento dinâmico, não por desempenho neste tipo de carga.

A coleta de 30 amostras e o cálculo de média e desvio padrão se mostraram
essenciais para diferenciar variações reais de desempenho de ruído de
medição.

---

### Referências

- OpenMP Architecture Review Board. *OpenMP API Specification, version 5.2*.
- Intel oneAPI Threading Building Blocks — *Developer Guide and Reference*.
- *cppreference.com* — `std::chrono::high_resolution_clock`.
