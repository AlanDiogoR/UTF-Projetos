/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Excecao lancada quando a placa esta vazia, repetida ou nao esta cadastrada
public class PlacaInvalidaException extends Exception {

    public PlacaInvalidaException() {
        super("Placa invalida: vazia, repetida ou nao cadastrada.");
    }
}
