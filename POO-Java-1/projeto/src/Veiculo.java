/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

// Classe mae dos veiculos (Carro, Moto e Caminhonete sao um tipo de Veiculo)
public abstract class Veiculo {

    private String placa;
    private String modelo;
    private String cor;
    private LocalDateTime horaEntrada;
    private Cliente proprietario;

    public Veiculo() {
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa; //Reflexividade
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo; //Reflexividade
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor; //Reflexividade
    }

    public LocalDateTime getHoraEntrada() {
        return horaEntrada;
    }

    public void setHoraEntrada(LocalDateTime horaEntrada) {
        this.horaEntrada = horaEntrada; //Reflexividade
    }

    public Cliente getProprietario() {
        return proprietario;
    }

    public void setProprietario(Cliente proprietario) {
        this.proprietario = proprietario; //Reflexividade
    }

    // cada filha diz qual tipo de vaga ela precisa
    public abstract String getTipoVaga();

    //Sobrescrita
    @Override
    public String toString() {
        String entrada = "fora do patio";
        if (getHoraEntrada() != null) {
            entrada = getHoraEntrada().format(DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm"));
        }
        return "Placa: " + getPlaca() + " | Modelo: " + getModelo() + " | Cor: " + getCor()
                + " | Dono: " + getProprietario().getNome() + " | Entrada: " + entrada;
    }
}
