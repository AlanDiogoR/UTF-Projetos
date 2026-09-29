public class Prof extends Pessoa {//Tipo Abstrato de Dados

	private int sal;
	private String titulo;
	
//========================================
	public Prof(){
		System.out.println("\n Construtor Default de Prof -> Filha");
		sal = 0;
		titulo = "";
	}
	
	public Prof(int ra, String curso){
		System.out.println("\n Construtor SOBREC1 de Prof -> Filha");
		this.sal = sal;
		this.titulo = titulo;
	}
	

	public int getSal(){
		return sal;		
	}
	
	
	public String getTitulo(){
		return titulo;
	}
	
	public void setSal(int sal){
		this.sal = sal;
	}
	
	public void setTitulo(String titulo){
		this.titulo = titulo;
	}


}// fim da classe