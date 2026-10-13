// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstInt {

    // i) Classe Integer: metodo parseInt()
    // ii) O metodo convertStr_Int(String) converte o texto recebido para o tipo primitivo int.
    //     Se o texto nao for um inteiro valido, o parseInt lanca NumberFormatException.
    // iii) Referencia: Oracle. Java SE 21 API, classe Integer.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Integer.html
    public int convertStr_Int(String val_Str) {
        return Integer.parseInt(val_Str);
    }

    // i) Classe Integer: metodo toString()
    // ii) O metodo convertInt_Str(int) converte um valor int para String.
    // iii) Referencia: Oracle. Java SE 21 API, classe Integer.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Integer.html
    public String convertInt_Str(int val_Int) {
        return Integer.toString(val_Int);
    }

    // i) Classe Integer: metodo toBinaryString()
    // ii) O metodo intParaBinario(int) devolve a representacao do int em base 2 (binario).
    // iii) Referencia: Oracle. Java SE 21 API, classe Integer.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Integer.html
    public String intParaBinario(int val_Int) {
        return Integer.toBinaryString(val_Int);
    }
}
