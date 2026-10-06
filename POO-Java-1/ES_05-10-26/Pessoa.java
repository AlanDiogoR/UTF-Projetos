public class Pessoa{

	private int cpf = 0;
	private String nome = "";
	
	public int getCpf(){
		return cpf;
	}

	public String getNome(){
		return nome;
	}
//===============================================
// THROWS (com 's') --> AVISO: POSSO lançar um Objt. do tipo "tal"
// THROW (sem 's') --> ORDEM: LANCE um OBjto. do tipo "tal"

	public void setCpf(int cpf)throws CpfPeqException{
		if(cpf >= 0){
			this.cpf = cpf;
		}
		else{
			throw new CpfPeqException();
		}
	}
	
	
//===============================================
	
	public void setNome(String nome){
		this.nome = nome;
	}


}