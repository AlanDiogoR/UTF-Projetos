// RA: 2809311
// Nome: Alan Diogo Ribeiro de Carvalho

public class Passeio extends Veiculo implements Calc {

    private int qtdePassageiro;

    public Passeio() {
        super();
        this.qtdePassageiro = 0;
    }

    public Passeio(String placa, String marca, String modelo, String cor, int qtdRodas,
                   int velocMax, Motor motor, String dataCadastro, int qtdePassageiro) {
        super(placa, marca, modelo, cor, qtdRodas, velocMax, motor, dataCadastro);
        this.qtdePassageiro = qtdePassageiro;
    }

    public int getQtdePassageiro() {
        return qtdePassageiro;
    }

    public void setQtdePassageiro(int qtdePassageiro) {
        this.qtdePassageiro = qtdePassageiro;
    }

    // Sobrescrita: converte Km/h (valor armazenado) para M/h (metros por hora)
    @Override
    public int calcVel() {
        return getVelocMax() * 1000;
    }

    // Soma das quantidades de letras de todos os atributos String (os 4 + data de cadastro).
    // Conta apenas letras: digitos e simbolos (ex.: numeros da placa, barras da data) ficam de fora.
    @Override
    public int calcular() {
        return contarLetras(getPlaca())
                + contarLetras(getMarca())
                + contarLetras(getModelo())
                + contarLetras(getCor())
                + contarLetras(getDataCadastro());
    }

    private int contarLetras(String texto) {
        int total = 0;
        for (int i = 0; i < texto.length(); i++) {
            if (Character.isLetter(texto.charAt(i))) {
                total++;
            }
        }
        return total;
    }
}
