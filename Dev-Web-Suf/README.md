# Horizon Studio — Site Institucional

Projeto desenvolvido como **Exame de Suficiência** das disciplinas **AS62F / ES44C / EC47C — Programação Web Front-End** da UTFPR (Universidade Tecnológica Federal do Paraná).

Trata-se do site institucional fictício de um estúdio indie de desenvolvimento de jogos chamado **Horizon Studio**, com áreas pública (apresentação, cadastro, login) e um painel administrativo que armazena dados localmente no navegador.

## Integrante

- **Alan Diogo Ribeiro de Carvalho**
  Engenharia de Software — UTFPR Cornélio Procópio

## Tecnologias

- **HTML5** com tags semânticas (`header`, `nav`, `main`, `section`, `article`, `footer`, `figure`)
- **CSS3** com **Flexbox** para layout e responsividade
- **JavaScript** puro (ES6+), sem bibliotecas
- **Web Storage API** (`localStorage` / `sessionStorage`) para persistência local
- **DOM API** para manipulação dinâmica de elementos
- **Font Awesome 6** (via CDN com **SRI**) para ícones
- **Google Fonts** (Orbitron + Inter) para tipografia

## Estrutura do projeto

```
Dev-Web-Suf/
├── index.html
├── cadastro.html
├── login.html
├── admin.html
├── curriculo.html
├── Curriculo_AlanDiogoR_PT.pdf
│
├── comum/
│   ├── comum.css
│   ├── formularios.js      Envio POST sem expor dados na URL
│   └── curriculo.css
│
├── index/index.css
├── cadastro/cadastro.css
├── login/login.css
│
├── admin/
│   ├── admin.css
│   ├── admin.js
│   └── gate.js             Proteção simples do painel (demonstração)
│
├── img/
│   ├── aurora.svg
│   ├── pixel.svg
│   └── mindloop.svg
│
├── scripts/
│   └── gerar-curriculo-pdf.py
└── README.md
```

## Segurança e boas práticas (front-end estático)

| Item | Implementação |
|------|----------------|
| Formulários cadastro/login | `method="post"` + `comum/formularios.js` intercepta o envio e redireciona **sem** colocar senha ou dados na URL |
| Painel admin | Senha de demonstração: **`horizon2026`** (validada em `admin/gate.js`, sessão em `sessionStorage`) |
| CDN Font Awesome | Atributo `integrity` (SRI) + `crossorigin="anonymous"` |
| Links externos | `rel="noopener noreferrer"` no currículo em PDF |
| Dados do admin | `localStorage`; nomes renderizados com `createTextNode` (mitiga XSS) |

> **Importante:** não há backend nem autenticação real. A senha do admin existe apenas para fins didáticos em site estático.

## Funcionalidades

### Página principal (`index.html`)
- Hero, jogos, destaques, sobre e contato
- Capas dos jogos em SVG (`img/`)
- Mensagem de feedback após login (flash via `sessionStorage`)

### Cadastro (`cadastro.html`)
Formulário com 6 campos; envio seguro redireciona para `login.html` sem query string.

### Login (`login.html`)
E-mail e senha; após envio, redireciona para `index.html` com mensagem de confirmação (demonstração).

### Painel Admin (`admin.html`)
CRUD em `localStorage` (chave `horizon_usuarios`). Acesso protegido por senha de demonstração.

### Currículo
- **PDF:** `Curriculo_AlanDiogoR_PT.pdf`
- **HTML:** `curriculo.html` (pode usar *Salvar como PDF* no navegador)

Regenerar o PDF:

```bash
python scripts/gerar-curriculo-pdf.py
```

## Como executar localmente

1. Clone ou baixe o repositório.
2. Abra `index.html` no navegador ou use um servidor local:

```bash
cd Dev-Web-Suf
python -m http.server 8000
```

3. Acesse `http://localhost:8000/Dev-Web-Suf/` (ajuste o caminho conforme a pasta servida).

### Testar o admin

1. Abra `admin.html`.
2. Informe a senha: **`horizon2026`**.

## Publicação

Site publicado no **GitHub Pages**:

**https://alandiogor.github.io/UTF-Projetos/Dev-Web-Suf/**

(Se a raiz do Pages for outra pasta, ajuste o caminho `/Dev-Web-Suf/` conforme a configuração do repositório.)

## Validação W3C

- HTML: <https://validator.w3.org/>
- CSS: <https://jigsaw.w3.org/css-validator/>

Avisos comuns do validador CSS (não são erros de segurança):

- Uso de `var(--...)` — variáveis CSS não são verificadas estaticamente.
- Prefixos `-webkit-` em `background-clip: text` — compatibilidade com navegadores WebKit.

## Cores e fontes

| Variável CSS         | Cor       | Uso                          |
|----------------------|-----------|------------------------------|
| `--cor-fundo`        | `#0f1226` | Fundo principal              |
| `--cor-superficie`   | `#1b1f3a` | Fundo de cards/seções        |
| `--cor-primaria`     | `#7b5cff` | Roxo neon — destaques        |
| `--cor-secundaria`   | `#00e0c6` | Turquesa — links/acentos     |
| `--cor-texto`        | `#f2f3ff` | Texto principal              |
| `--cor-texto-suave`  | `#b8bbd9` | Texto secundário             |
| `--cor-perigo`       | `#ff5577` | Botões de exclusão           |

| Fonte       | Família           | Uso        |
|-------------|-------------------|------------|
| **Orbitron**| Display/Tech      | Títulos    |
| **Inter**   | Sans-serif moderna| Corpo      |

## Licença

Projeto acadêmico — uso educacional.
