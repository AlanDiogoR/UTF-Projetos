public class Prof extends Pessoa implements IProf{//Tipo Abstrato de Dados

	private int sal;
	private String titulo;
	
//========================================
	public Prof(){
		System.out.println("\n Construtor Default de Prof -> Filha");
		sal = 0;
		titulo = "";
	}
	
	public Prof(int sal, String titulo){
		System.out.println("\n Construtor SOBREC1 de Prof -> Filha");
		this.sal = sal;
		this.titulo = titulo;
	}

	public void printDados(){
		System.out.println("\n\t printDados da classe-filha Prof");
		System.out.println("\tSALARIO: "+sal);
		System.out.println("\tTITULO: "+titulo);
		System.out.println("\tCPF: "+getCpf());
		System.out.println("\tNOME: "+getNome());
		System.out.println("\tRUA: "+getEnder().getRua());
		System.out.println("\tNUMERO: "+getEnder().getNum());
		System.out.println("\tCIDADE: "+getEnder().getLocal().getCidade());
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