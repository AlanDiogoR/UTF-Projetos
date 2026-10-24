/*
 * Aluno: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 * Disciplina: Programacao Orientada a Objetos (ES43B) - UTFPR
 * Projeto: Estacionamento - Entrega Parcial
 */

// Entidade que representa o dono do veiculo
public class Cliente {

    private String nome;
    private String telefone;

    public Cliente() {
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome; //Reflexividade
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone; //Reflexividade
    }

    //Sobrescrita
    @Override
    public String toString() {
        return "Cliente: " + getNome() + " | Telefone: " + getTelefone();
    }
}
