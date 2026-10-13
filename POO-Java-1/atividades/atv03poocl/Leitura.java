// Aluno: Alan Diogo Ribeiro de Carvalho

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Leitura {

    private BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));

    // Exibe a mensagem na tela (saida) e devolve o texto digitado (entrada)
    public String entDados(String mensagem) {
        System.out.print(mensagem);
        try {
            String linha = teclado.readLine();
            if (linha == null) {
                System.out.println("Entrada encerrada.");
                System.exit(0);
            }
            return linha.trim();
        } catch (IOException e) {
            System.out.println("Erro de entrada.");
            return "";
        }
    }
}
