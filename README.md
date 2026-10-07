# UTF-Projetos

<p align="center">
  <img src="assets/utfpr-logo.png" alt="Logotipo da UTFPR" height="110">
</p>

<p align="center">
  Trabalhos, exercícios e projetos do curso de <strong>Engenharia de Software</strong><br>
  da <strong>Universidade Tecnológica Federal do Paraná (UTFPR)</strong>.
</p>

---

## Sumário

- [Sobre](#sobre)
- [Stack](#stack)
- [Destaques](#destaques)
- [Conteúdo por disciplina](#conteúdo-por-disciplina)
- [Como compilar e executar](#como-compilar-e-executar)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Licença](#licença)
- [Autor](#autor)

---

## Sobre

Este repositório reúne a minha produção acadêmica ao longo da graduação, organizada **por disciplina**. Há desde exercícios de fundamentos de programação em C até projetos completos: um site front-end publicado no GitHub Pages, um experimento de programação paralela com OpenMP e Intel TBB e uma simulação de concorrência com semáforos.

> Por ser um repositório de estudos, parte dos arquivos são exercícios feitos em sala ou rascunhos de aula. Alguns deles não compilam sozinhos.

---

## Stack

| Linguagem / ferramenta | Onde aparece |
| :--- | :--- |
| **C** | Algoritmos 1 e 2, Estruturas de Dados (ponteiros, structs, alocação dinâmica, listas encadeadas) |
| **Java** | Programação Orientada a Objetos (classes, herança, interfaces, exceções) |
| **C++** | Herança múltipla (POO) e soma paralela de vetor com **OpenMP** e **Intel TBB** (Sistemas Operacionais) |
| **HTML5, CSS3, JavaScript** | Site Horizon Studio (Web Front-End) e simulação Produtor-Consumidor (SO) |
| **SQL** | Scripts DDL de Banco de Dados (criação de banco e tabelas) |
| **Python** | Geração de gráficos e estatísticas (Matplotlib) e geração de PDF |
| **brModelo · MySQL Workbench** | Modelagem conceitual e lógica (`.brM3`, `.mwb`) |
| **GitHub Actions** | Deploy automático da pasta `Dev-Web-Suf/` no GitHub Pages |

---

## Destaques

### Horizon Studio: site institucional (Web Front-End)

Site de um estúdio indie de jogos fictício, feito como Exame de Suficiência de Programação Web Front-End. Tem páginas públicas (início, cadastro, login), currículo em HTML/PDF e um painel administrativo com CRUD de usuários em `localStorage`. Foi escrito em HTML semântico, CSS com Flexbox e JavaScript puro, sem bibliotecas.

- **Site publicado:** <https://alandiogor.github.io/UTF-Projetos/>
- **Código e detalhes:** [`Dev-Web-Suf/`](Dev-Web-Suf/README.md)

### Soma de vetor: sequencial × OpenMP × Intel TBB (Sistemas Operacionais)

Programa em C++17 que soma um vetor grande de três formas: laço sequencial, `#pragma omp parallel for reduction` e `tbb::parallel_reduce`. Cada abordagem roda várias vezes, os tempos vão para um CSV e scripts em Python calculam média, desvio padrão e *speedup* e geram os gráficos. A pasta inclui Makefile, scripts de execução para Linux e Windows e um relatório técnico.

- **Código e detalhes:** [`Sistemas-Operacionais/concorrencia-soma-vetor/`](Sistemas-Operacionais/concorrencia-soma-vetor/README.md)

### Produtor-Consumidor com semáforos (Sistemas Operacionais)

Simulação no navegador do problema Produtor-Consumidor: três produtores e dois consumidores dividem um buffer circular. Os semáforos (`mutex`, `empty`, `full`) foram implementados em JavaScript com `async/await`, e a ordem fixa de aquisição evita deadlock.

- **Código:** [`Sistemas-Operacionais/concorrencia-produtor-consumidor/`](Sistemas-Operacionais/concorrencia-produtor-consumidor/)

### Lista encadeada simples em C (Estruturas de Dados)

Implementação de lista encadeada com inicialização, inserção no início, impressão, verificação de lista vazia, contagem, soma, busca, maior valor e liberação de memória.

- **Código:** [`ESD-1/06-10-lista-encadeada/atividade_lista_encadeada.c`](ESD-1/06-10-lista-encadeada/atividade_lista_encadeada.c)

---

## Conteúdo por disciplina

### Algoritmos 1: `Algorithms-1/`

Fundamentos de programação em C.

| Pasta | Conteúdo |
| :--- | :--- |
| `book/` | Exercícios do livro-texto, separados por página |
| `class/` | Exercícios feitos em aula |
| `list/` | Listas de exercícios |
| `Vetor/` · `revisao-p2/` | Vetores e matrizes |
| `funçoes/` · `modules/` | Funções e modularização |
| `struct/` | Estruturas (`struct`) |
| `revisao-p1/` · `revisao-p2/` · `revisao-p3/` | Revisões para as provas |
| `assets/` | Exercícios extras e de reforço |

As pastas `output/` guardam executáveis (`.exe`) gerados no Windows durante as aulas.

### Algoritmos 2: `Algorithms-2/`

Alocação dinâmica em C: vetor que cresce com `realloc`, função que devolve um novo vetor alocado (`int *Maiores(...)`) e soma de matrizes M×N alocadas dinamicamente. Os exercícios de aula estão em `class/<data>/`.

Na raiz do repositório, `questao01.c` é um sistema de cadastro com `struct`s que relaciona proprietários, veículos e viagens, com validação de datas e quilometragem.

### Estruturas de Dados: `ESD-1/`

Exercícios em C de condicionais e ponteiros, um trabalho sobre listas encadeadas (inserção no início, com material de entrega em PDF) e a lista encadeada completa citada em [Destaques](#lista-encadeada-simples-em-c-estruturas-de-dados).

### Programação Orientada a Objetos: `POO-Java-1/`

| Pasta | Conteúdo |
| :--- | :--- |
| raiz · `31-08/` | Primeiras classes e objetos em Java, entrada e saída de dados |
| `ES_28-09-26/` | Herança e **interfaces** (`IPessoa`, `IAluno`, `IProf`, `IConvidado`, `IEndereco`, `ILocal`), diagramas de classes sobre acoplamento e coesão |
| `ES_29-09-26/` | Herança em Java e um exemplo de **herança múltipla em C++** (`HerMult.cpp`) |
| `ES_05-10-26/` | **Tratamento de exceções** com exceções próprias (`CpfPeqException`, `CpfGrdException`, `NomePeqException`, `NomeInvalidoException`) e `try/catch` |

### Banco de Dados: `Database-1/`

Modelos conceitual e lógico no brModelo, diagrama no MySQL Workbench e scripts SQL em versões (`v1`, `v2`, `v3`) que criam o banco e as tabelas (alunos, cursos, cidades, departamentos).

### Programação Web Front-End: `Dev-Web-Suf/`

Projeto Horizon Studio. Veja [Destaques](#horizon-studio-site-institucional-web-front-end) e o [README da pasta](Dev-Web-Suf/README.md).

### Sistemas Operacionais: `Sistemas-Operacionais/`

| Pasta / arquivo | Conteúdo |
| :--- | :--- |
| `concorrencia-soma-vetor/` | Experimento de paralelismo com OpenMP e Intel TBB, com relatório |
| `concorrencia-produtor-consumidor/` | Simulação Produtor-Consumidor com semáforos |
| `escalonamento-processos/` | Atividade sobre escalonamento de processos |
| `Aula_9_*` | Material sobre cálculo de *turnaround* e tempo de espera |

---

## Como compilar e executar

Os comandos abaixo partem da raiz do repositório.

**Pré-requisitos:** `gcc`/`g++`, JDK 8 ou superior (`javac`/`java`), Python 3 e um navegador.

### C

```bash
gcc -Wall -o lista ESD-1/06-10-lista-encadeada/atividade_lista_encadeada.c
./lista
```

O mesmo padrão vale para os outros arquivos `.c`: `gcc -Wall -o programa caminho/arquivo.c`.

### Java

Cada pasta de POO é um conjunto independente de classes. Compile a pasta inteira e rode a classe que tem o `main`:

```bash
# Interfaces e herança (o argumento "demo" preenche dados de exemplo)
javac -encoding UTF-8 -d out POO-Java-1/ES_28-09-26/*.java
java -cp out TstInt demo

# Tratamento de exceções (lê CPF e nome pelo teclado)
javac -encoding UTF-8 -d out-exc POO-Java-1/ES_05-10-26/*.java
java -cp out-exc TstTratExc
```

### Web (Horizon Studio e Produtor-Consumidor)

São páginas estáticas: basta abrir o `index.html` no navegador ou servir a pasta localmente:

```bash
python3 -m http.server 8000 --directory Dev-Web-Suf
# acesse http://localhost:8000
```

### C++ com OpenMP e TBB

O passo a passo (dependências, `make`, scripts e geração de gráficos) está no [README do experimento](Sistemas-Operacionais/concorrencia-soma-vetor/README.md).

---

## Estrutura do repositório

```text
UTF-Projetos/
├── Algorithms-1/            # Algoritmos 1 (C)
├── Algorithms-2/            # Algoritmos 2 (C, alocação dinâmica)
├── Database-1/              # Banco de Dados (brModelo, MySQL Workbench, SQL)
├── Dev-Web-Suf/             # Web Front-End: site Horizon Studio
├── ESD-1/                   # Estruturas de Dados (C)
├── POO-Java-1/              # Programação Orientada a Objetos (Java)
├── Sistemas-Operacionais/   # Concorrência, paralelismo e escalonamento
├── assets/                  # Imagens usadas no README
├── .github/workflows/       # Deploy do Dev-Web-Suf no GitHub Pages
├── AlgoritmosFinal1.pdf     # Material de Algoritmos
├── questao01.c              # Sistema de cadastro de veículos e viagens (C)
└── LICENSE
```

---

## Licença

Distribuído sob a licença **MIT**. Veja [LICENSE](LICENSE).

---

## Autor

**Alan Diogo**, estudante de Engenharia de Software na UTFPR. GitHub: [@AlanDiogoR](https://github.com/AlanDiogoR)
