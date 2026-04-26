# Concorrência em S.O. — Soma de Vetor (Sequencial × OpenMP × TBB)

> Atividade da disciplina **Sistemas Operacionais** — UTFPR / Engenharia de Software.

Comparação de desempenho da soma dos elementos de um vetor de **10⁸ elementos**
em três abordagens: sequencial (loop `for`), paralela com **OpenMP** e paralela
com **Intel TBB** (`parallel_reduce`). Mede-se o tempo de cada abordagem em **30
execuções**, calculando média, desvio padrão e gerando gráficos.

---

## Estrutura

```
concorrencia-soma-vetor/
├── src/
│   └── somar_vetor.cpp        # Programa principal (3 abordagens + cronometragem)
├── scripts/
│   ├── executar_experimento.sh   # Pipeline (Linux / WSL / macOS)
│   ├── executar_experimento.ps1  # Pipeline (Windows / PowerShell)
│   └── gerar_graficos.py         # Estatísticas e gráficos (Matplotlib)
├── resultados/                # CSVs e PNGs gerados pela execução
├── relatorio/
│   └── relatorio.md           # Relatório técnico (≤ 5 páginas)
├── Makefile
├── requirements.txt
└── README.md
```

---

## Pré-requisitos

| Componente | Linux/WSL | Windows |
| :--- | :--- | :--- |
| Compilador | `g++` 9+ | MSYS2 / MinGW-w64 com `g++` |
| OpenMP | já incluso no `g++` (flag `-fopenmp`) | idem |
| Intel TBB | `sudo apt-get install libtbb-dev` | `pacman -S mingw-w64-x86_64-tbb` (MSYS2) |
| Python 3.9+ | `python3 -m pip install -r requirements.txt` | `py -m pip install -r requirements.txt` |

---

## Como executar

### Linux / WSL / macOS

```bash
cd Sistemas-Operacionais/concorrencia-soma-vetor

# pipeline completa (compila → executa → gera gráficos)
chmod +x scripts/executar_experimento.sh
./scripts/executar_experimento.sh 30 100000000

# alternativa via Makefile
make            # compila
make run        # executa o experimento
make grafico    # gera gráficos
```

### Windows (PowerShell)

```powershell
cd Sistemas-Operacionais\concorrencia-soma-vetor
powershell -ExecutionPolicy Bypass -File scripts\executar_experimento.ps1 30 100000000
```

### Compilação manual (referência)

```bash
g++ -O2 -std=c++17 -Wall -Wextra -fopenmp -DUSE_TBB \
    src/somar_vetor.cpp -o somar_vetor -ltbb

./somar_vetor 30 100000000
python scripts/gerar_graficos.py
```

> **Importante:** o programa C++ **executa internamente as 30 repetições** de
> cada abordagem (evita o overhead de iniciar o processo várias vezes) e grava
> `resultados/tempos.csv`. Em Linux você ainda pode envolver a chamada com
> `time ./somar_vetor` para obter o tempo total de wall-clock pedido pelo
> enunciado.

---

## Saídas geradas em `resultados/`

| Arquivo | Conteúdo |
| :--- | :--- |
| `tempos.csv` | Tempo (s) das 30 execuções de cada abordagem |
| `estatisticas.csv` | Média, desvio padrão, mínimo, máximo e *speedup* |
| `grafico_sequencial.png` | Curva das 30 execuções — Sequencial |
| `grafico_openmp.png` | Curva das 30 execuções — OpenMP |
| `grafico_tbb.png` | Curva das 30 execuções — Intel TBB |
| `grafico_comparativo.png` | Sobreposição das três abordagens |
| `grafico_boxplot.png` | *Boxplot* da distribuição dos tempos |

---

## Sobre a implementação

- **Sequencial:** loop `for` clássico (`O(n)`), sem qualquer paralelismo.
- **OpenMP:** `#pragma omp parallel for reduction(+: soma) schedule(static)`.
  O `reduction` evita *race conditions* somando parcialmente em cada thread e
  agregando ao final.
- **Intel TBB:** `tbb::parallel_reduce` sobre `tbb::blocked_range` — divisão
  recursiva do intervalo do vetor entre os *workers* e combinação via `std::plus`.

A soma de referência (calculada pela versão sequencial) é comparada com as
versões paralelas a cada execução; qualquer divergência é reportada com
`[DIVERGENTE!]` no console.

---

## Relatório

O relatório técnico (≤ 5 páginas) está em
[`relatorio/relatorio.md`](relatorio/relatorio.md). Ele cobre introdução,
metodologia, resultados (média e desvio padrão), gráficos das 30 execuções,
discussão e conclusão.

---

## Autor

Alan Diogo R. — alandiogor@gmail.com
