public class Pessoa {
    static int cpf = 0;
    static String nome = "";

    public static void main(String arg[]) {
        int a = 7;
        String b = "dsds";

        entDados(a, b);
        impDados();
    };

    public static void entDados(int c, String n) {
        cpf = c;
        nome = n;
    }

    public static void impDados() {
        System.out.println("\n CPF: "+cpf);
        System.out.println("\n Nome: "+nome);

    }
}