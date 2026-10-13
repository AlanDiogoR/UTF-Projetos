// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstChar {

    // i) Classe Character: metodo isDigit()
    // ii) O metodo contarDigitos(String) percorre a frase e conta quantos caracteres sao digitos (0 a 9).
    // iii) Referencia: Oracle. Java SE 21 API, classe Character.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Character.html
    public int contarDigitos(String frase) {
        int total = 0;
        for (int i = 0; i < frase.length(); i++) {
            if (Character.isDigit(frase.charAt(i))) {
                total++;
            }
        }
        return total;
    }

    // i) Classe Character: metodos isUpperCase(), toLowerCase() e toUpperCase()
    // ii) O metodo inverterCaixa(char) troca maiuscula por minuscula e vice-versa. Se o
    //     caractere nao for uma letra, ele e devolvido sem alteracao.
    // iii) Referencia: Oracle. Java SE 21 API, classe Character.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Character.html
    public char inverterCaixa(char letra) {
        if (Character.isUpperCase(letra)) {
            return Character.toLowerCase(letra);
        }
        return Character.toUpperCase(letra);
    }
}
