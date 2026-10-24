/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

// Entidade que guarda a entrada e a saida de um veiculo
public class Ticket {

    private int codigo;
    private Veiculo veiculo;
    private Vaga vaga;
    private LocalDateTime entrada;
    private LocalDateTime saida;
    private double valor;

    public Ticket() {
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo; //Reflexividade
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo; //Reflexividade
    }

    public Vaga getVaga() {
        return vaga;
    }

    public void setVaga(Vaga vaga) {
        this.vaga = vaga; //Reflexividade
    }

    public LocalDateTime getEntrada() {
        return entrada;
    }

    public void setEntrada(LocalDateTime entrada) {
        this.entrada = entrada; //Reflexividade
    }

    public LocalDateTime getSaida() {
        return saida;
    }

    public void setSaida(LocalDateTime saida) {
        this.saida = saida; //Reflexividade
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor; //Reflexividade
    }

    //Sobrescrita
    @Override
    public String toString() {
        DateTimeFormatter f = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
        String textoSaida = "em aberto";
        if (getSaida() != null) {
            textoSaida = getSaida().format(f) + " | Valor: R$ " + String.format("%.2f", getValor());
        }
        return "Ticket " + getCodigo() + " | Placa: " + getVeiculo().getPlaca() + " | Vaga: "
                + getVaga().getNumero() + " | Entrada: " + getEntrada().format(f) + " | Saida: " + textoSaida;
    }
}
