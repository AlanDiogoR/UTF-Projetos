/* =========================================================
   GATE.JS — Proteção simples do painel admin (demonstração)
   Senha padrão documentada no README: horizon2026
   ========================================================= */

(function () {
  'use strict';

  const SENHA_DEMO = 'horizon2026';
  const CHAVE_SESSAO = 'horizon_admin_autenticado';
  const MAX_TENTATIVAS = 5;

  const gateEl = document.getElementById('gateAdmin');
  const appEl = document.getElementById('appAdmin');
  const formGate = document.getElementById('formGate');
  const inputSenha = document.getElementById('gateSenha');
  const gateErro = document.getElementById('gateErro');

  if (!gateEl || !appEl || !formGate || !inputSenha) return;

  function liberarPainel() {
    sessionStorage.setItem(CHAVE_SESSAO, '1');
    gateEl.classList.add('escondida');
    gateEl.setAttribute('aria-hidden', 'true');
    appEl.classList.remove('escondida');
    appEl.removeAttribute('aria-hidden');
  }

  function negarAcesso(mensagem) {
    if (gateErro) {
      gateErro.textContent = mensagem;
      gateErro.classList.remove('escondida');
    }
    inputSenha.value = '';
    inputSenha.focus();
  }

  if (sessionStorage.getItem(CHAVE_SESSAO) === '1') {
    liberarPainel();
    return;
  }

  let tentativas = 0;

  formGate.addEventListener('submit', function (evento) {
    evento.preventDefault();

    const senha = inputSenha.value;

    if (senha === SENHA_DEMO) {
      liberarPainel();
      return;
    }

    tentativas++;
    if (tentativas >= MAX_TENTATIVAS) {
      alert('Muitas tentativas. Voltando à página inicial.');
      window.location.assign('index.html');
      return;
    }

    negarAcesso('Senha incorreta. Tente novamente.');
  });
})();
