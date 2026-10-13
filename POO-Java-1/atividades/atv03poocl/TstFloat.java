// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstFloat {

    // i) Classe Float: metodo parseFloat()
    // ii) O metodo convertStr_Float(String) converte o texto para float. O separador decimal
    //     deve ser o ponto (2.5). Texto invalido lanca NumberFormatException.
    // iii) Referencia: Oracle. Java SE 21 API, classe Float.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Float.html
    public float convertStr_Float(String val_Str) {
        return Float.parseFloat(val_Str);
    }

    // i) Classe Float: metodo floatToIntBits()
    // ii) O metodo bitsIEEE754(float) devolve, em hexadecimal, os 32 bits que representam o
    //     float no padrao IEEE 754 (1 bit de sinal, 8 de expoente e 23 de mantissa).
    // iii) Referencia: Oracle. Java SE 21 API, classe Float.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Float.html
    public String bitsIEEE754(float val_Float) {
        int bits = Float.floatToIntBits(val_Float);
        return String.format("0x%08X", bits);
    }
}
