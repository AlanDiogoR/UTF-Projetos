// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstShort {

    // i) Classe Short: metodo parseShort()
    // ii) O metodo convertStr_Short(String) converte o texto para short. O tipo short aceita
    //     valores de -32768 a 32767; fora dessa faixa e lancada NumberFormatException.
    // iii) Referencia: Oracle. Java SE 21 API, classe Short.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Short.html
    public short convertStr_Short(String val_Str) {
        return Short.parseShort(val_Str);
    }

    // i) Classe Short: metodo reverseBytes()
    // ii) O metodo inverterBytes(short) troca a ordem dos dois bytes do valor
    //     (conversao entre big-endian e little-endian).
    // iii) Referencia: Oracle. Java SE 21 API, classe Short.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Short.html
    public short inverterBytes(short val_Short) {
        return Short.reverseBytes(val_Short);
    }
}
