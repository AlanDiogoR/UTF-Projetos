# UTF-Projetos

<p align="center">
  <img src="assets/utfpr-logo.png" alt="Logotipo UTFPR" height="120">
</p>

---

## Sobre o repositório

Repositório de **materiais acadêmicos** do curso de **Engenharia de Software** da **Universidade Tecnológica Federal do Paraná (UTFPR)** — exercícios, listas, diagramas e projetos práticos organizados **por disciplina e por período**, no mesmo espírito de pastas separadas (por exemplo `Algorithms-1` / `Algorithms-2` e `Database-1` / `Database-2`).

---

## Estrutura do projeto

Visão geral da organização na raiz do repositório:

```
UTF-Projetos/
├── Algorithms-1/          # Algoritmos e Programação — 1º período
│   ├── book/              # Exercícios do livro-texto
│   ├── class/             # Aulas e atividades em sala
│   ├── list/              # Listas complementares
│   ├── revisao-p1/        # Revisão — primeira prova
│   ├── revisao-p2/        # Revisão — segunda prova (matrizes)
│   ├── struct/            # Structs
│   ├── Vetor/             # Vetores
│   ├── assets/            # Extras e reforço
│   └── …
├── Algorithms-2/          # Algoritmos e Programação — 2º período
│   └── class/             # Aulas por data (ex.: 18-03/)
├── Database-1/            # Banco de Dados — 1º período (modelagem inicial)
│   ├── Conceitual_1.brM3  # Modelo conceitual (brModelo)
│   └── diagram-mysql.mwb  # Diagrama MySQL Workbench
├── Database-2/            # Banco de Dados — 2º período
│   └── class/
│       └── 24-03/         # Atividades por data (ex.: modelos lógico/conceitual)
├── assets/                # Recursos globais (ex.: utfpr-logo.png)
├── AlgoritmosFinal1.pdf   # Material de referência (algoritmos)
├── LICENSE
└── README.md
```

Novos arquivos de **aula** em Banco de Dados podem seguir o padrão `Database-2/class/<data>/`, alinhado a `Algorithms-2/class/<data>/`.

---

## Conteúdos por disciplina

### Algoritmos e Programação (C)

Implementações em **C** (estruturado): lógica, condicionais, laços, vetores, matrizes, funções e structs. Detalhamento por pastas em `Algorithms-1` e continuidade em `Algorithms-2`.

| Tópico | Diretórios típicos |
| :--- | :--- |
| Fundamentos, controle de fluxo | `Algorithms-1/assets`, `Algorithms-1/book`, `Algorithms-1/class`, `Algorithms-1/list` |
| Vetores e matrizes | `Algorithms-1/Vetor`, `Algorithms-1/revisao-p2` |
| Funções e structs | `Algorithms-1/class`, `Algorithms-1/list`, `Algorithms-1/struct` |
| 2º período | `Algorithms-2/class` |

### Banco de Dados

Materiais de **modelagem** e **diagramas**: arquivos **brModelo** (`.brM3`) e **MySQL Workbench** (`.mwb`), separados entre `Database-1` (base do 1º período) e `Database-2` (atividades atuais do 2º período).

---

## Tecnologias e ferramentas

| Área | Uso |
| :--- | :--- |
| **C** | Código dos algoritmos (GCC ou Clang recomendados) |
| **brModelo** | Modelagem conceitual/lógica (`.brM3`) |
| **MySQL Workbench** | Diagramas e modelagem física (`.mwb`) |

### Compilar um `.c` com GCC

```bash
gcc exemplo.c -o exemplo
./exemplo
```

---

## Como contribuir

1. Faça um **fork** do projeto.
2. Crie uma **branch** (`git checkout -b feature/descricao`).
3. **Commit** com mensagem clara.
4. **Push** e abra um **pull request**.

---

## Licença

Este projeto está sob a licença **MIT**. Veja [LICENSE](LICENSE).

---

## Contato

Alan Diogo R. — alandiogor@gmail.com

Projeto: [https://github.com/AlanDiogoR/UTF-Projetos](https://github.com/AlanDiogoR/UTF-Projetos)
