// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstDoub {

    // i) Classe Double: metodo parseDouble()
    // ii) O metodo convertStr_Doub(String) converte o texto para double. O separador decimal
    //     deve ser o ponto (3.14). Texto invalido lanca NumberFormatException.
    // iii) Referencia: Oracle. Java SE 21 API, classe Double.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Double.html
    public double convertStr_Doub(String val_Str) {
        return Double.parseDouble(val_Str);
    }

    // i) Classe Double: metodos isNaN() e isInfinite()
    // ii) O metodo analisarDivisao(double, double) divide a por b e usa isNaN() e isInfinite()
    //     para identificar resultados especiais: 0.0/0.0 e NaN (indefinido) e n/0.0 e infinito.
    //     Com double nao ocorre ArithmeticException, diferente da divisao entre inteiros.
    // iii) Referencia: Oracle. Java SE 21 API, classe Double.
    //      Disponivel em: https://docs.oracle.com/en/java/javase/21/docs/api/java.base/java/lang/Double.html
    public String analisarDivisao(double a, double b) {
        double resultado = a / b;
        if (Double.isNaN(resultado)) {
            return "indefinido (NaN)";
        }
        if (Double.isInfinite(resultado)) {
            return "infinito";
        }
        return String.valueOf(resultado);
    }
}
