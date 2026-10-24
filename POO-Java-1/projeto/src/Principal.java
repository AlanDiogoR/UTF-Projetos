/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Classe principal: cria os controles e trata o menu com switch/case
public class Principal {

    public static void main(String[] args) {
        Leitura leitura = new Leitura();

        ControleMenu menu = new ControleMenu();
        menu.setLeitura(leitura);
        ControleCliente controleCliente = new ControleCliente();
        controleCliente.setLeitura(leitura);
        ControleVeiculo controleVeiculo = new ControleVeiculo();
        controleVeiculo.setLeitura(leitura);
        controleVeiculo.setControleCliente(controleCliente);
        ControleVaga controleVaga = new ControleVaga();
        controleVaga.setLeitura(leitura);
        ControleTicket controleTicket = new ControleTicket();
        controleTicket.setLeitura(leitura);
        controleTicket.setControleVeiculo(controleVeiculo);
        controleTicket.setControleVaga(controleVaga);

        int opcao;
        do {
            opcao = menu.exibirMenu();
            switch (opcao) {
                case 1:
                    controleCliente.cadastrarCliente();
                    break;
                case 2:
                    controleVeiculo.cadastrarVeiculo();
                    break;
                case 3:
                    controleVaga.cadastrarVaga();
                    break;
                case 4:
                    controleTicket.registrarEntrada();
                    break;
                case 5:
                    controleTicket.registrarSaida();
                    break;
                case 6:
                    controleVeiculo.consultarPlaca();
                    break;
                case 7:
                    controleCliente.listarClientes();
                    break;
                case 8:
                    controleVeiculo.listarVeiculos();
                    break;
                case 9:
                    controleVaga.listarVagas();
                    break;
                case 10:
                    controleVaga.listarVagas(true);
                    break;
                case 11:
                    controleTicket.listarTickets();
                    break;
                case 0:
                    menu.mostrarMensagem("Saindo do sistema...");
                    break;
                default:
                    menu.mostrarMensagem("Opcao invalida!");
            }
        } while (opcao != 0);
    }
}
