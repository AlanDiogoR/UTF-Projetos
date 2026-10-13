// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstBool {

    // i) Classe Boolean: metodo parseBoolean()
    // ii) O metodo convertStr_Bool(String) converte o texto para boolean. Devolve true somente
    //     se o texto for "true" (sem diferenciar maiusculas de minusculas); qualquer outro
    //     texto resulta em false.
    // iii) Referencia: Oracle. Java SE 21 API, classe Boolean.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Boolean.html
    public boolean convertStr_Bool(String val_Str) {
        return Boolean.parseBoolean(val_Str);
    }

    // i) Classe Boolean: metodo logicalXor()
    // ii) O metodo xorLogico(boolean, boolean) aplica o OU EXCLUSIVO: devolve true somente
    //     quando os dois valores sao diferentes.
    // iii) Referencia: Oracle. Java SE 21 API, classe Boolean.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Boolean.html
    public boolean xorLogico(boolean a, boolean b) {
        return Boolean.logicalXor(a, b);
    }
}
