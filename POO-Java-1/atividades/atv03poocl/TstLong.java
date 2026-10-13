// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstLong {

    // i) Classe Long: metodo parseLong()
    // ii) O metodo convertStr_Long(String) converte o texto para long (64 bits). Texto
    //     invalido ou fora da faixa do tipo lanca NumberFormatException.
    // iii) Referencia: Oracle. Java SE 21 API, classe Long.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Long.html
    public long convertStr_Long(String val_Str) {
        return Long.parseLong(val_Str);
    }

    // i) Classe Long: metodo toHexString()
    // ii) O metodo longParaHex(long) devolve a representacao do valor em base 16 (hexadecimal).
    // iii) Referencia: Oracle. Java SE 21 API, classe Long.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Long.html
    public String longParaHex(long val_Long) {
        return Long.toHexString(val_Long);
    }
}
