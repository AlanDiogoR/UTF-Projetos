/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

import java.util.ArrayList;

// Controle das vagas: cadastro, busca de vaga livre e relatorios
public class ControleVaga {

    private ArrayList<Vaga> vagas = new ArrayList<>();
    private Leitura leitura;

    public ControleVaga() {
    }

    public void setLeitura(Leitura leitura) {
        this.leitura = leitura; //Reflexividade
    }

    public void cadastrarVaga() {
        Vaga vaga = new Vaga();
        vaga.setNumero(leitura.entInteiro("Numero da vaga (int): "));
        String tipo = leitura.entDados("Tipo da vaga (String: CARRO/MOTO/CAMINHONETE): ").toUpperCase();
        if (!tipo.equals("CARRO") && !tipo.equals("MOTO") && !tipo.equals("CAMINHONETE")) {
            System.out.println("Tipo de vaga invalido.");
            return;
        }
        vaga.setTipoVaga(tipo);
        vaga.setOcupada(false);
        vagas.add(vaga);
        System.out.println("Vaga cadastrada!");
    }

    public Vaga buscarVagaLivre(String tipoVaga) throws VagaIndisponivelException {
        for (Vaga v : vagas) {
            if (!v.isOcupada() && v.getTipoVaga().equals(tipoVaga)) {
                return v;
            }
        }
        throw new VagaIndisponivelException();
    }

    public void listarVagas() {
        System.out.println("--- Todas as vagas ---");
        for (Vaga v : vagas) {
            System.out.println(v);
        }
    }

    // lista so as livres (true) ou so as ocupadas (false)
    //Sobrecarga
    public void listarVagas(boolean livres) {
        System.out.println(livres ? "--- Vagas livres ---" : "--- Vagas ocupadas ---");
        for (Vaga v : vagas) {
            if (v.isOcupada() != livres) {
                System.out.println(v);
            }
        }
    }
}
