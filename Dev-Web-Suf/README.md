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
- **Web Storage API** (`localStorage`) para persistência local
- **DOM API** para manipulação dinâmica de elementos
- **Font Awesome 6** (via CDN) para ícones
- **Google Fonts** (Orbitron + Inter) para tipografia

## Estrutura do projeto

```
Dev-Web-Suf/
├── index.html                  Página principal (home)
├── cadastro.html               Formulário de cadastro de conta
├── login.html                  Formulário de login
├── admin.html                  Painel administrativo (CRUD via localStorage)
│
├── comum/
│   └── comum.css               Estilos compartilhados (header, footer, menu, botões, fontes, cores)
│
├── index/
│   └── index.css               Estilos exclusivos da página principal
│
├── cadastro/
│   └── cadastro.css            Estilos exclusivos da página de cadastro
│
├── login/
│   └── login.css               Estilos exclusivos da página de login
│
├── admin/
│   ├── admin.css               Estilos exclusivos do painel admin
│   └── admin.js                Lógica do painel (cadastrar, excluir, pesquisar, limpar)
│
├── img/
│   ├── aurora.png              Capa do jogo "Aurora Drift"
│   ├── pixel.png               Capa do jogo "Pixel Rush"
│   └── mindloop.png            Capa do jogo "Mindloop"
│
├── Curriculo_AlanDiogoR_PT.pdf Currículo do desenvolvedor (linkado no rodapé)
└── README.md                   Este arquivo
```

### Padrão de organização

Cada página HTML carrega **dois arquivos CSS**:

1. `comum/comum.css` — estilos repetidos em todas as páginas (cabeçalho, menu, rodapé, botões, variáveis de cor, fontes).
2. `<pagina>/<pagina>.css` — estilos específicos daquela página.

Isso evita duplicação de código e mantém manutenção fácil.

## Funcionalidades

### Página principal (`index.html`)
- Cabeçalho com logo e menu de navegação responsivo
- Seção **hero** com chamada principal e botões de ação
- Galeria de **3 jogos** com imagens, descrição e categoria
- Lista de **destaques** com ícones do Font Awesome
- Seções **Sobre** e **Contato**
- Rodapé com menu secundário e **link para o currículo em PDF**

### Cadastro (`cadastro.html`)
Formulário com **6 campos** (nome, e-mail, telefone, data de nascimento, jogo favorito, senha) que, ao ser enviado, redireciona o usuário para a página de login.

### Login (`login.html`)
Formulário de autenticação simples (e-mail + senha) com link para a página de cadastro.

### Painel Admin (`admin.html` + `admin/admin.js`)
Implementado **sem bibliotecas externas**, usando apenas **DOM API** + **Web Storage API**.

| Funcionalidade            | Descrição                                                                              |
|---------------------------|----------------------------------------------------------------------------------------|
| **Cadastrar usuário**     | Adiciona um novo usuário (nome + e-mail) à lista e ao `localStorage`, com data/hora.   |
| **Limpar campos**         | Esvazia os inputs do formulário.                                                       |
| **Excluir item**          | Remove um usuário específico da lista e do `localStorage` (com confirmação).           |
| **Excluir todos**         | Limpa toda a lista e o `localStorage` (com confirmação).                               |
| **Pesquisar**             | Filtra a lista exibindo apenas usuários cujo nome ou e-mail combine com o termo.       |

Os dados ficam salvos no navegador sob a chave `horizon_usuarios`, em formato JSON.

## Como executar localmente

Não há build nem dependências — basta abrir o arquivo no navegador:

1. Clone ou baixe o repositório.
2. Abra o arquivo `index.html` no seu navegador (duplo clique ou *Abrir com…*).
3. Navegue pelo menu para acessar as demais páginas.

> Para testar o painel administrativo, abra `admin.html` e cadastre alguns usuários. Os dados persistem entre recarregamentos da página (até serem excluídos manualmente ou o `localStorage` do navegador ser limpo).

### Servidor local (opcional)

Se quiser servir os arquivos via HTTP (recomendado para alguns navegadores em modo restrito):

```bash
# Python 3
python -m http.server 8000

# Node.js (com npx)
npx serve .
```

Depois acesse `http://localhost:8000` no navegador.

## Publicação

O projeto está publicado no **GitHub Pages**:

> *(adicionar URL após a publicação — ver instruções abaixo)*

### Como publicar

1. Crie um repositório no GitHub (público) e suba todos os arquivos do projeto.
2. Em **Settings → Pages**, selecione a branch `main` e a pasta `/ (root)`.
3. Salve. Após alguns minutos, a URL pública estará disponível em
   `https://<seu-usuario>.github.io/<nome-do-repositorio>/`.

## Validação W3C

O código foi validado nos validadores oficiais:

- HTML: <https://validator.w3.org/>
- CSS: <https://jigsaw.w3.org/css-validator/>

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
