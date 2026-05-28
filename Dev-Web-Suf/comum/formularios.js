/* =========================================================
   FORMULARIOS.JS — Envio seguro (POST + sem dados na URL)
   Horizon Studio — demonstração front-end estática
   ========================================================= */

(function () {
  'use strict';

  const CHAVE_FLASH = 'horizon_flash_msg';

  function exibirFlash() {
    const msg = sessionStorage.getItem(CHAVE_FLASH);
    if (!msg) return;

    sessionStorage.removeItem(CHAVE_FLASH);
    const alvo = document.getElementById('mensagemFlash');
    if (!alvo) return;

    alvo.textContent = msg;
    alvo.classList.remove('escondida');
  }

  function configurarFormulario(form, destino, mensagemFlash) {
    if (!form) return;

    form.addEventListener('submit', function (evento) {
      evento.preventDefault();

      if (!form.checkValidity()) {
        form.reportValidity();
        return;
      }

      if (mensagemFlash) {
        sessionStorage.setItem(CHAVE_FLASH, mensagemFlash);
      }

      window.location.assign(destino);
    });
  }

  configurarFormulario(
    document.getElementById('formCadastro'),
    'login.html',
    'Cadastro enviado com sucesso (demonstração). Nenhum dado foi colocado na URL.'
  );

  configurarFormulario(
    document.getElementById('formLogin'),
    'index.html',
    'Login realizado (demonstração). Bem-vindo à Horizon Studio!'
  );

  exibirFlash();
})();
