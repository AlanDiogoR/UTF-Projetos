// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstByte {

    // i) Classe Byte: metodo parseByte()
    // ii) O metodo convertStr_Byte(String) converte o texto para byte. O tipo byte aceita
    //     apenas valores de -128 a 127; fora dessa faixa e lancada NumberFormatException.
    // iii) Referencia: Oracle. Java SE 21 API, classe Byte.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Byte.html
    public byte convertStr_Byte(String val_Str) {
        return Byte.parseByte(val_Str);
    }

    // i) Classe Byte: metodo toUnsignedInt()
    // ii) O metodo byteSemSinal(byte) interpreta o byte sem sinal, devolvendo um int de 0 a 255
    //     (por exemplo, o byte -1 vira 255).
    // iii) Referencia: Oracle. Java SE 21 API, classe Byte.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Byte.html
    public int byteSemSinal(byte val_Byte) {
        return Byte.toUnsignedInt(val_Byte);
    }
}
