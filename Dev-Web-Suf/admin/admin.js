/* =========================================================
   ADMIN.JS — Lógica da página administrativa
   Sem bibliotecas externas. Apenas DOM API + Web Storage API.
   Horizon Studio — Exame de Suficiência (UTFPR)
   ========================================================= */

(function () {
  'use strict';

  // ---------- Constantes ----------
  const CHAVE_STORAGE = 'horizon_usuarios';

  // ---------- Referências do DOM ----------
  const inputNome       = document.getElementById('adminNome');
  const inputEmail      = document.getElementById('adminEmail');
  const inputBusca      = document.getElementById('campoBusca');
  const listaUsuariosEl = document.getElementById('listaUsuarios');
  const mensagemListaEl = document.getElementById('mensagemLista');

  const btnCadastrar    = document.getElementById('btnCadastrar');
  const btnLimpar       = document.getElementById('btnLimpar');
  const btnPesquisar    = document.getElementById('btnPesquisar');
  const btnExcluirTodos = document.getElementById('btnExcluirTodos');

  // Termo de busca atual (mantido em memória para reaplicar quando a lista é re-renderizada).
  let termoBusca = '';

  // ---------- Persistência (Web Storage API) ----------
  function carregarUsuarios() {
    try {
      const json = localStorage.getItem(CHAVE_STORAGE);
      if (!json) return [];
      const dados = JSON.parse(json);
      return Array.isArray(dados) ? dados : [];
    } catch (erro) {
      console.error('Falha ao ler usuários do localStorage:', erro);
      return [];
    }
  }

  function salvarUsuarios(usuarios) {
    localStorage.setItem(CHAVE_STORAGE, JSON.stringify(usuarios));
  }

  // ---------- Utilitários ----------
  function gerarId() {
    return 'u_' + Date.now().toString(36) + '_' + Math.random().toString(36).slice(2, 8);
  }

  function formatarData(timestamp) {
    const d = new Date(timestamp);
    const dia  = String(d.getDate()).padStart(2, '0');
    const mes  = String(d.getMonth() + 1).padStart(2, '0');
    const ano  = d.getFullYear();
    const hora = String(d.getHours()).padStart(2, '0');
    const min  = String(d.getMinutes()).padStart(2, '0');
    return `${dia}/${mes}/${ano} ${hora}:${min}`;
  }

  function emailValido(email) {
    // Validação simples (sem regex complexa): precisa de @ e ponto depois.
    const arroba = email.indexOf('@');
    const ponto  = email.lastIndexOf('.');
    return arroba > 0 && ponto > arroba + 1 && ponto < email.length - 1;
  }

  // ---------- Renderização da lista ----------
  function renderizarLista() {
    const usuarios = carregarUsuarios();

    // Limpa a lista atual no DOM
    listaUsuariosEl.innerHTML = '';

    if (usuarios.length === 0) {
      mensagemListaEl.textContent = 'Nenhum usuário cadastrado ainda.';
      mensagemListaEl.classList.remove('escondida');
      return;
    }

    const termo = termoBusca.trim().toLowerCase();
    let visiveis = 0;

    // Itera do mais recente para o mais antigo
    for (let i = usuarios.length - 1; i >= 0; i--) {
      const usuario = usuarios[i];
      const li = criarItemLista(usuario);

      // Aplica o filtro de pesquisa (se houver)
      if (termo !== '') {
        const correspondeNome  = usuario.nome.toLowerCase().includes(termo);
        const correspondeEmail = usuario.email.toLowerCase().includes(termo);
        if (!correspondeNome && !correspondeEmail) {
          li.classList.add('escondido');
        } else {
          visiveis++;
        }
      } else {
        visiveis++;
      }

      listaUsuariosEl.appendChild(li);
    }

    if (visiveis === 0) {
      mensagemListaEl.textContent = `Nenhum usuário encontrado para "${termoBusca}".`;
      mensagemListaEl.classList.remove('escondida');
    } else {
      mensagemListaEl.classList.add('escondida');
    }
  }

  function criarItemLista(usuario) {
    const li = document.createElement('li');
    li.className = 'item-usuario';
    li.dataset.id = usuario.id;

    // Container com os dados do usuário
    const dados = document.createElement('div');
    dados.className = 'dados-usuario';

    const spanNome = document.createElement('span');
    spanNome.className = 'nome-usuario';
    spanNome.innerHTML = '<i class="fa-solid fa-user"></i>';
    spanNome.append(document.createTextNode(' ' + usuario.nome));

    const spanEmail = document.createElement('span');
    spanEmail.className = 'email-usuario';
    spanEmail.innerHTML = '<i class="fa-solid fa-envelope"></i>';
    spanEmail.append(document.createTextNode(' ' + usuario.email));

    const spanData = document.createElement('span');
    spanData.className = 'data-usuario';
    spanData.innerHTML = '<i class="fa-regular fa-clock"></i>';
    spanData.append(document.createTextNode(' ' + formatarData(usuario.dataEnvio)));

    dados.appendChild(spanNome);
    dados.appendChild(spanEmail);
    dados.appendChild(spanData);

    // Botão de exclusão individual
    const btnExcluir = document.createElement('button');
    btnExcluir.type = 'button';
    btnExcluir.className = 'botao-excluir-item';
    btnExcluir.setAttribute('aria-label', `Excluir ${usuario.nome}`);
    btnExcluir.innerHTML = '<i class="fa-solid fa-trash"></i> Excluir';
    btnExcluir.addEventListener('click', function () {
      excluirItem(usuario.id, usuario.nome);
    });

    li.appendChild(dados);
    li.appendChild(btnExcluir);

    return li;
  }

  // ---------- Função: cadastrar ----------
  function cadastrar() {
    const nome  = inputNome.value.trim();
    const email = inputEmail.value.trim();

    if (nome === '' || email === '') {
      alert('Por favor, preencha o nome e o e-mail.');
      return;
    }

    if (!emailValido(email)) {
      alert('Por favor, informe um e-mail válido (exemplo@dominio.com).');
      inputEmail.focus();
      return;
    }

    const usuarios = carregarUsuarios();

    const novoUsuario = {
      id: gerarId(),
      nome: nome,
      email: email,
      dataEnvio: Date.now()
    };

    usuarios.push(novoUsuario);
    salvarUsuarios(usuarios);

    limparCampos();
    renderizarLista();
    inputNome.focus();
  }

  // ---------- Função: excluir um item ----------
  function excluirItem(id, nome) {
    const confirmacao = confirm(`Deseja realmente excluir "${nome}"?`);
    if (!confirmacao) return;

    const usuarios = carregarUsuarios();
    const filtrados = usuarios.filter(function (u) {
      return u.id !== id;
    });

    salvarUsuarios(filtrados);
    renderizarLista();
  }

  // ---------- Função: excluir todos ----------
  function excluirTodos() {
    const usuarios = carregarUsuarios();
    if (usuarios.length === 0) {
      alert('A lista já está vazia.');
      return;
    }

    const confirmacao = confirm(
      `Tem certeza que deseja excluir TODOS os ${usuarios.length} usuários? Esta ação não pode ser desfeita.`
    );
    if (!confirmacao) return;

    localStorage.removeItem(CHAVE_STORAGE);
    renderizarLista();
  }

  // ---------- Função: pesquisar ----------
  function pesquisar() {
    termoBusca = inputBusca.value;
    renderizarLista();
  }

  // ---------- Função: limpar campos do formulário ----------
  function limparCampos() {
    inputNome.value = '';
    inputEmail.value = '';
    inputNome.focus();
  }

  // ---------- Event listeners ----------
  btnCadastrar.addEventListener('click', cadastrar);
  btnLimpar.addEventListener('click', limparCampos);
  btnPesquisar.addEventListener('click', pesquisar);
  btnExcluirTodos.addEventListener('click', excluirTodos);

  // Pesquisa dinâmica enquanto digita
  inputBusca.addEventListener('input', pesquisar);

  // Enter no campo de busca também pesquisa
  inputBusca.addEventListener('keydown', function (e) {
    if (e.key === 'Enter') {
      e.preventDefault();
      pesquisar();
    }
  });

  // Enter nos campos do formulário envia o cadastro
  [inputNome, inputEmail].forEach(function (input) {
    input.addEventListener('keydown', function (e) {
      if (e.key === 'Enter') {
        e.preventDefault();
        cadastrar();
      }
    });
  });

  // ---------- Inicialização ----------
  renderizarLista();
})();
