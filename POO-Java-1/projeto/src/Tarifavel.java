/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Interface implementada pelos veiculos que pagam tarifa no estacionamento
public interface Tarifavel {

    // tempo de tolerancia: ate 15 minutos o cliente nao paga
    public static final int TOLERANCIA_MINUTOS = 15;

    // calcula a tarifa cobrando por hora
    public double calcularTarifa(int minutos);

    // calcula a tarifa podendo cobrar por diaria
    //Sobrecarga
    public double calcularTarifa(int minutos, boolean diaria);
}
