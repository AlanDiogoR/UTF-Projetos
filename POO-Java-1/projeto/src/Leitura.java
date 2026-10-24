/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.util.Scanner;

// Classe auxiliar de leitura do teclado (usada pelas classes de Controle)
public class Leitura {

    private Scanner teclado = new Scanner(System.in);

    public String entDados(String rotulo) {
        System.out.print(rotulo);
        if (!teclado.hasNextLine()) {
            return "0";
        }
        return teclado.nextLine().trim();
    }

    // le um numero inteiro, repetindo ate o usuario digitar certo
    public int entInteiro(String rotulo) {
        while (true) {
            try {
                return Integer.parseInt(entDados(rotulo));
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro.");
            }
        }
    }

    // le um numero real, repetindo ate o usuario digitar certo
    public double entReal(String rotulo) {
        while (true) {
            try {
                return Double.parseDouble(entDados(rotulo).replace(",", "."));
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero (ex.: 750,5).");
            }
        }
    }
}
