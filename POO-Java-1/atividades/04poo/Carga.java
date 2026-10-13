// RA: 2809311
// Nome: Alan Diogo Ribeiro de Carvalho

public class Carga extends Veiculo implements Calc {

    private int tara;
    private int cargaMax;

    public Carga() {
        super();
        this.tara = 0;
        this.cargaMax = 0;
    }

    public Carga(String placa, String marca, String modelo, String cor, int qtdRodas,
                 int velocMax, Motor motor, String dataCadastro, int tara, int cargaMax) {
        super(placa, marca, modelo, cor, qtdRodas, velocMax, motor, dataCadastro);
        this.tara = tara;
        this.cargaMax = cargaMax;
    }

    public int getTara() {
        return tara;
    }

    public void setTara(int tara) {
        this.tara = tara;
    }

    public int getCargaMax() {
        return cargaMax;
    }

    public void setCargaMax(int cargaMax) {
        this.cargaMax = cargaMax;
    }

    // Sobrescrita: converte Km/h (valor armazenado) para Cm/h (centimetros por hora)
    @Override
    public int calcVel() {
        return getVelocMax() * 100000;
    }

    // Soma dos valores de todos os atributos numericos da classe (proprios e herdados):
    // qtdRodas, velocMax, tara e cargaMax.
    @Override
    public int calcular() {
        return getQtdRodas() + getVelocMax() + tara + cargaMax;
    }
}
