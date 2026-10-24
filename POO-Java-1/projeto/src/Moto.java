/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Moto: R$ 3,00 por hora (ou fracao), diaria R$ 18,00. Moto com bau paga R$ 0,50 a mais por hora
public class Moto extends Veiculo implements Tarifavel {

    private int cilindradas;
    private boolean temBau;

    public Moto() {
    }

    public int getCilindradas() {
        return cilindradas;
    }

    public void setCilindradas(int cilindradas) {
        this.cilindradas = cilindradas; //Reflexividade
    }

    public boolean isTemBau() {
        return temBau;
    }

    public void setTemBau(boolean temBau) {
        this.temBau = temBau; //Reflexividade
    }

    //Sobrescrita
    @Override
    public String getTipoVaga() {
        return "MOTO";
    }

    //Sobrescrita
    @Override
    public double calcularTarifa(int minutos) {
        if (minutos <= TOLERANCIA_MINUTOS) {
            return 0;
        }
        int horas = (minutos + 59) / 60;
        double valorHora = 3.0;
        if (isTemBau()) {
            valorHora = 3.5;
        }
        return horas * valorHora;
    }

    //Sobrecarga
    @Override
    public double calcularTarifa(int minutos, boolean diaria) {
        if (!diaria) {
            return calcularTarifa(minutos);
        }
        if (minutos <= TOLERANCIA_MINUTOS) {
            return 0;
        }
        int dias = (minutos + 1439) / 1440;
        return dias * 18.0;
    }

    //Sobrescrita
    @Override
    public String toString() {
        return "[Moto] " + super.toString() + " | Cilindradas: " + getCilindradas()
                + " | Bau: " + (isTemBau() ? "sim" : "nao");
    }
}
