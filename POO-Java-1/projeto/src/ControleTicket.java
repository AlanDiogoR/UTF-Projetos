/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.time.Duration;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;

// Controle dos tickets: entrada, saida (com tarifa) e relatorio
public class ControleTicket {

    private ArrayList<Ticket> tickets = new ArrayList<>();
    private Leitura leitura;
    private ControleVeiculo controleVeiculo;
    private ControleVaga controleVaga;
    private int proximoCodigo = 1;
    private DateTimeFormatter formato = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");

    public ControleTicket() {
    }

    public void setLeitura(Leitura leitura) {
        this.leitura = leitura; //Reflexividade
    }

    public void setControleVeiculo(ControleVeiculo controleVeiculo) {
        this.controleVeiculo = controleVeiculo; //Reflexividade
    }

    public void setControleVaga(ControleVaga controleVaga) {
        this.controleVaga = controleVaga; //Reflexividade
    }

    // le data e hora no formato dd/mm/aaaa hh:mm, repetindo se digitar errado
    private LocalDateTime lerDataHora(String rotulo) {
        while (true) {
            try {
                return LocalDateTime.parse(leitura.entDados(rotulo), formato);
            } catch (DateTimeParseException e) {
                System.out.println("Formato invalido. Use dd/mm/aaaa hh:mm.");
            }
        }
    }

    public void registrarEntrada() {
        String placa = leitura.entDados("Placa do veiculo (String): ");
        Veiculo veiculo;
        try {
            veiculo = controleVeiculo.buscarPorPlaca(placa);
        } catch (PlacaInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
            return;
        }
        if (veiculo.getHoraEntrada() != null) {
            System.out.println("Este veiculo ja esta no patio.");
            return;
        }
        Vaga vaga;
        try {
            vaga = controleVaga.buscarVagaLivre(veiculo.getTipoVaga());
        } catch (VagaIndisponivelException e) {
            System.out.println("Erro: " + e.getMessage());
            return;
        }
        LocalDateTime entrada = lerDataHora("Data/hora de entrada (dd/mm/aaaa hh:mm): ");
        vaga.setOcupada(true);
        veiculo.setHoraEntrada(entrada);
        Ticket ticket = new Ticket();
        ticket.setCodigo(proximoCodigo);
        proximoCodigo++;
        ticket.setVeiculo(veiculo);
        ticket.setVaga(vaga);
        ticket.setEntrada(entrada);
        tickets.add(ticket);
        System.out.println("Entrada registrada: " + ticket);
    }

    public void registrarSaida() {
        String placa = leitura.entDados("Placa do veiculo (String): ");
        Veiculo veiculo;
        try {
            veiculo = controleVeiculo.buscarPorPlaca(placa);
        } catch (PlacaInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
            return;
        }
        Ticket ticket = buscarTicketAberto(veiculo);
        if (ticket == null) {
            System.out.println("Este veiculo nao esta no patio.");
            return;
        }
        LocalDateTime saida = lerDataHora("Data/hora de saida (dd/mm/aaaa hh:mm): ");
        if (saida.isBefore(ticket.getEntrada())) {
            System.out.println("A saida nao pode ser antes da entrada.");
            return;
        }
        boolean diaria = leitura.entDados("Cobrar por diaria? (S/N): ").equalsIgnoreCase("S");
        int minutos = (int) Duration.between(ticket.getEntrada(), saida).toMinutes();

        // todas as filhas de Veiculo implementam Tarifavel
        Tarifavel tarifavel = (Tarifavel) veiculo;
        double valor;
        if (diaria) {
            valor = tarifavel.calcularTarifa(minutos, true);
        } else {
            valor = tarifavel.calcularTarifa(minutos);
        }

        ticket.setSaida(saida);
        ticket.setValor(valor);
        ticket.getVaga().setOcupada(false);
        veiculo.setHoraEntrada(null);
        System.out.println("Permanencia: " + minutos + " min (tolerancia de "
                + Tarifavel.TOLERANCIA_MINUTOS + " min)");
        System.out.println("Saida registrada: " + ticket);
    }

    private Ticket buscarTicketAberto(Veiculo veiculo) {
        for (Ticket t : tickets) {
            if (t.getVeiculo() == veiculo && t.getSaida() == null) {
                return t;
            }
        }
        return null;
    }

    public void listarTickets() {
        System.out.println("--- Tickets ---");
        if (tickets.isEmpty()) {
            System.out.println("Nenhum ticket.");
        }
        for (Ticket t : tickets) {
            System.out.println(t);
        }
    }
}
