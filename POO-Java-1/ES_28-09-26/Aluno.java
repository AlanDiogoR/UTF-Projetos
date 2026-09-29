public class Aluno extends Pessoa {//Tipo Abstrato de Dados

	private int ra;
	private String curso;
	
//========================================	

public void printDados(){
	System.out.println("\n\t printDados da classe-filha Aluno");
}
		
//========================================
	public Aluno(){
		System.out.println("\n Construtor Default de Aluno -> Filha");
		ra = 0;
		curso = "";
	}
//========================================
	public void altCodP(){
		codP = 10;
		System.out.println("\nValor de codP: "+codP);
	}
//========================================	
	
	public Aluno(int ra, String curso){
		System.out.println("\n Construtor SOBREC1 de Aluno -> Filha");
		this.ra = ra;
		this.curso = curso;
	}
	

	public int getRa(){
		return ra;		
	}
	
	
	public String getCurso(){
		return curso;
	}
	
	public void setRa(int ra){
		this.ra = ra;
	}
	
	public void setCurso(String curso){
		this.curso = curso;
	} 



}// fim da classe