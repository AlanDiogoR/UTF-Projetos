/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Caminhonete: R$ 8,00 por hora (ou fracao), diaria R$ 55,00.
// Carga acima de 1000 kg paga R$ 2,00 a mais por hora; cabine dupla paga R$ 10,00 a mais na diaria
public class Caminhonete extends Veiculo implements Tarifavel {

    private double capacidadeCargaKg;
    private boolean cabineDupla;

    public Caminhonete() {
    }

    public double getCapacidadeCargaKg() {
        return capacidadeCargaKg;
    }

    public void setCapacidadeCargaKg(double capacidadeCargaKg) {
        this.capacidadeCargaKg = capacidadeCargaKg; //Reflexividade
    }

    public boolean isCabineDupla() {
        return cabineDupla;
    }

    public void setCabineDupla(boolean cabineDupla) {
        this.cabineDupla = cabineDupla; //Reflexividade
    }

    //Sobrescrita
    @Override
    public String getTipoVaga() {
        return "CAMINHONETE";
    }

    //Sobrescrita
    @Override
    public double calcularTarifa(int minutos) {
        if (minutos <= TOLERANCIA_MINUTOS) {
            return 0;
        }
        int horas = (minutos + 59) / 60;
        double valorHora = 8.0;
        if (getCapacidadeCargaKg() > 1000) {
            valorHora = 10.0;
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
        double valorDiaria = 55.0;
        if (isCabineDupla()) {
            valorDiaria = 65.0;
        }
        return dias * valorDiaria;
    }

    //Sobrescrita
    @Override
    public String toString() {
        return "[Caminhonete] " + super.toString() + " | Carga: " + getCapacidadeCargaKg()
                + " kg | Cabine dupla: " + (isCabineDupla() ? "sim" : "nao");
    }
}
