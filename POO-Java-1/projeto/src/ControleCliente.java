/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.util.ArrayList;

// Controle dos clientes: cadastro, busca e relatorio
public class ControleCliente {

    private ArrayList<Cliente> clientes = new ArrayList<>();
    private Leitura leitura;

    public ControleCliente() {
    }

    public void setLeitura(Leitura leitura) {
        this.leitura = leitura; //Reflexividade
    }

    public Cliente cadastrarCliente() {
        Cliente cliente = new Cliente();
        cliente.setNome(leitura.entDados("Nome do cliente (String): "));
        cliente.setTelefone(leitura.entDados("Telefone (String, ex.: 43999990000): "));
        clientes.add(cliente);
        System.out.println("Cliente cadastrado!");
        return cliente;
    }

    // procura o cliente pelo nome (sem diferenciar maiusculas)
    public Cliente buscarPorNome(String nome) {
        for (Cliente c : clientes) {
            if (c.getNome().equalsIgnoreCase(nome)) {
                return c;
            }
        }
        return null;
    }

    public void listarClientes() {
        System.out.println("--- Clientes ---");
        if (clientes.isEmpty()) {
            System.out.println("Nenhum cliente cadastrado.");
        }
        for (Cliente c : clientes) {
            System.out.println(c);
        }
    }
}
