/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Carro: R$ 6,00 por hora (ou fracao), diaria R$ 40,00. SUV paga R$ 1,00 a mais por hora
public class Carro extends Veiculo implements Tarifavel {

    private int numPortas;
    private String tipoCarroceria;

    public Carro() {
    }

    public int getNumPortas() {
        return numPortas;
    }

    public void setNumPortas(int numPortas) {
        this.numPortas = numPortas; //Reflexividade
    }

    public String getTipoCarroceria() {
        return tipoCarroceria;
    }

    public void setTipoCarroceria(String tipoCarroceria) {
        this.tipoCarroceria = tipoCarroceria; //Reflexividade
    }

    //Sobrescrita
    @Override
    public String getTipoVaga() {
        return "CARRO";
    }

    //Sobrescrita
    @Override
    public double calcularTarifa(int minutos) {
        if (minutos <= TOLERANCIA_MINUTOS) {
            return 0;
        }
        int horas = (minutos + 59) / 60;
        double valorHora = 6.0;
        if (getTipoCarroceria().equalsIgnoreCase("SUV")) {
            valorHora = 7.0;
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
        return dias * 40.0;
    }

    //Sobrescrita
    @Override
    public String toString() {
        return "[Carro] " + super.toString() + " | Portas: " + getNumPortas()
                + " | Carroceria: " + getTipoCarroceria();
    }
}
