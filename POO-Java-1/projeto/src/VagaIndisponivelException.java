/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Excecao lancada quando nao existe vaga livre do tipo do veiculo
public class VagaIndisponivelException extends Exception {

    public VagaIndisponivelException() {
        super("Nao ha vaga livre para este tipo de veiculo.");
    }
}
