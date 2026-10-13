// RA: 2809311
// Nome: Alan Diogo Ribeiro de Carvalho

public class Motor {

    private int qtdPistoes;
    private int potencia;

    // Construtor default: inicializa de acordo com o tipo de cada atributo
    public Motor() {
        this.qtdPistoes = 0;
        this.potencia = 0;
    }

    // Construtor sobrecarregado: inicializa com os parametros recebidos
    public Motor(int qtdPistoes, int potencia) {
        this.qtdPistoes = qtdPistoes;
        this.potencia = potencia;
    }

    public int getQtdPistoes() {
        return qtdPistoes;
    }

    public void setQtdPistoes(int qtdPistoes) {
        this.qtdPistoes = qtdPistoes;
    }

    public int getPotencia() {
        return potencia;
    }

    public void setPotencia(int potencia) {
        this.potencia = potencia;
    }
}
