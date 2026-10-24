/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Controle responsavel por mostrar o menu e ler a opcao
public class ControleMenu {

    private Leitura leitura;

    public ControleMenu() {
    }

    public void setLeitura(Leitura leitura) {
        this.leitura = leitura; //Reflexividade
    }

    public int exibirMenu() {
        System.out.println();
        System.out.println("===== ESTACIONAMENTO =====");
        System.out.println("1 - Cadastrar cliente");
        System.out.println("2 - Cadastrar veiculo");
        System.out.println("3 - Cadastrar vaga");
        System.out.println("4 - Registrar entrada");
        System.out.println("5 - Registrar saida");
        System.out.println("6 - Buscar veiculo por placa");
        System.out.println("7 - Relatorio de clientes");
        System.out.println("8 - Relatorio de veiculos");
        System.out.println("9 - Relatorio de todas as vagas");
        System.out.println("10 - Relatorio de vagas livres");
        System.out.println("11 - Relatorio de tickets");
        System.out.println("0 - Sair");
        return leitura.entInteiro("Opcao (int): ");
    }

    public void mostrarMensagem(String mensagem) {
        System.out.println(mensagem);
    }
}
