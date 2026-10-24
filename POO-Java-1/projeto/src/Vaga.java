/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Entidade que representa uma vaga do patio
public class Vaga {

    private int numero;
    private String tipoVaga;
    private boolean ocupada;

    public Vaga() {
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero; //Reflexividade
    }

    public String getTipoVaga() {
        return tipoVaga;
    }

    public void setTipoVaga(String tipoVaga) {
        this.tipoVaga = tipoVaga; //Reflexividade
    }

    public boolean isOcupada() {
        return ocupada;
    }

    public void setOcupada(boolean ocupada) {
        this.ocupada = ocupada; //Reflexividade
    }

    //Sobrescrita
    @Override
    public String toString() {
        return "Vaga " + getNumero() + " | Tipo: " + getTipoVaga() + " | " + (isOcupada() ? "OCUPADA" : "LIVRE");
    }
}
