// RA: 2809311
// Nome: Alan Diogo Ribeiro de Carvalho

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Leitura {

    private BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));

    // Recebe o texto que informa ao usuario qual dado sera digitado e devolve o que foi digitado
    public String entDados(String mensagem) {
        System.out.print(mensagem);
        try {
            String linha = teclado.readLine();
            if (linha == null) {
                System.exit(0);
            }
            return linha.trim();
        } catch (IOException e) {
            return "";
        }
    }
}
