public class Juventus {
    static int cpf = 0;
    static String nome = "";

    public static void main(String arg[]) {
       Juventus p; 
       p= new Juventus();

       //System.out.println("ender: "+p);

       p.entDados(32, "ola");

       p.impDados();

       System.out.println("Nome de p: "+p.nome);

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