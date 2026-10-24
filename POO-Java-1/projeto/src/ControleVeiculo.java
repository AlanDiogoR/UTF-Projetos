/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.util.ArrayList;

// Controle dos veiculos: cadastro (Carro, Moto ou Caminhonete), busca e relatorio
public class ControleVeiculo {

    private ArrayList<Veiculo> veiculos = new ArrayList<>();
    private Leitura leitura;
    private ControleCliente controleCliente;

    public ControleVeiculo() {
    }

    public void setLeitura(Leitura leitura) {
        this.leitura = leitura; //Reflexividade
    }

    public void setControleCliente(ControleCliente controleCliente) {
        this.controleCliente = controleCliente; //Reflexividade
    }

    public void cadastrarVeiculo() {
        Cliente dono = controleCliente.buscarPorNome(leitura.entDados("Nome do proprietario ja cadastrado (String): "));
        if (dono == null) {
            System.out.println("Cliente nao encontrado. Cadastre o cliente primeiro (opcao 1).");
            return;
        }
        String placa = leitura.entDados("Placa (String, ex.: ABC1D23): ").toUpperCase();
        try {
            validarPlaca(placa);
        } catch (PlacaInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
            return;
        }
        int tipo = leitura.entInteiro("Tipo (int: 1-Carro 2-Moto 3-Caminhonete): ");
        Veiculo veiculo;
        switch (tipo) {
            case 1:
                Carro carro = new Carro();
                carro.setNumPortas(leitura.entInteiro("Numero de portas (int): "));
                carro.setTipoCarroceria(leitura.entDados("Carroceria (String: HATCH/SEDAN/SUV): "));
                veiculo = carro;
                break;
            case 2:
                Moto moto = new Moto();
                moto.setCilindradas(leitura.entInteiro("Cilindradas (int): "));
                moto.setTemBau(leitura.entDados("Tem bau? (S/N): ").equalsIgnoreCase("S"));
                veiculo = moto;
                break;
            case 3:
                Caminhonete cam = new Caminhonete();
                cam.setCapacidadeCargaKg(leitura.entReal("Capacidade de carga em kg (double): "));
                cam.setCabineDupla(leitura.entDados("Cabine dupla? (S/N): ").equalsIgnoreCase("S"));
                veiculo = cam;
                break;
            default:
                System.out.println("Tipo invalido.");
                return;
        }
        veiculo.setPlaca(placa);
        veiculo.setModelo(leitura.entDados("Modelo (String): "));
        veiculo.setCor(leitura.entDados("Cor (String): "));
        veiculo.setProprietario(dono);
        veiculos.add(veiculo);
        System.out.println("Veiculo cadastrado!");
    }

    // a placa nao pode ser vazia nem repetida (nao valida o formato do documento)
    public void validarPlaca(String placa) throws PlacaInvalidaException {
        if (placa.isEmpty()) {
            throw new PlacaInvalidaException();
        }
        for (Veiculo v : veiculos) {
            if (v.getPlaca().equals(placa)) {
                throw new PlacaInvalidaException();
            }
        }
    }

    public Veiculo buscarPorPlaca(String placa) throws PlacaInvalidaException {
        for (Veiculo v : veiculos) {
            if (v.getPlaca().equalsIgnoreCase(placa)) {
                return v;
            }
        }
        throw new PlacaInvalidaException();
    }

    // opcao do menu: pergunta a placa e mostra o veiculo
    public void consultarPlaca() {
        String placa = leitura.entDados("Placa para buscar (String): ");
        try {
            Veiculo v = buscarPorPlaca(placa);
            System.out.println(v);
        } catch (PlacaInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }

    public void listarVeiculos() {
        System.out.println("--- Veiculos ---");
        if (veiculos.isEmpty()) {
            System.out.println("Nenhum veiculo cadastrado.");
        }
        for (Veiculo v : veiculos) {
            System.out.println(v);
        }
    }
}
