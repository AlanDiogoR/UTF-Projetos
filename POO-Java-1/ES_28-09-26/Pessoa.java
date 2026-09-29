public class Pessoa implements IPessoa{//Tipo Abstrato de Dados

	protected int codP;
	
	private int cpf;
	private String nome;
	private Endereco ender;
	
//========================================
	public Pessoa(){
		System.out.println("\n Construtor Default de Pessoa");
		cpf = 0;
		nome = "";
		ender = new Endereco();
		codP = 0;
	}
	
	public Pessoa(int cpf, String nome, Endereco ender, int codP){
		System.out.println("\n Construtor SOBREC1 de Pessoa");
		this.cpf = cpf;
		this.nome = nome;
		this.ender = ender;
		this.codP = codP;
	}
	
	public Pessoa(String n, int c, Endereco e){
		
		System.out.println("\n Construtor SOBREC2 de Pessoa");
				
		this.cpf = c;
		this.nome = n;
		this.ender = e;
		
	}	
//====================================
// Sobrecarga de outro método qualquer

public void impDados(){
	System.out.println("\n\t IMPDADOS VOID - DEFAULT");
}

public int impDados(int k){
	System.out.println("\n\t IMPDADOS int - SOBREC1");
	return k;
}

public void printDados(){
	System.out.println("\n\t printDados da classe-mãe Pessoa");
	System.out.println("\tCPF: "+cpf);
	System.out.println("\tNOME: "+nome);
	if(ender != null){
		System.out.println("\tRUA: "+ender.getRua());
		System.out.println("\tNUMERO: "+ender.getNum());
		if(ender.getLocal() != null){
			System.out.println("\tCIDADE: "+ender.getLocal().getCidade());
		}
	}
}	
	
//====================================	
	public Endereco getEnder(){
		return ender;		
	}
	public void setEnder(Endereco ender){
		this.ender = ender;
		
	}
//====================================
	
	public int getCpf(){
		return cpf;		
	}
	public int getCodP(){
		return codP;		
	}	
	
	
	public String getNome(){
		return nome;
	}
	
	public void setCpf(int cpf){
		this.cpf = cpf;
	}
	
	public void setCodP(int codP){
		this.codP = codP;
	}	
	
	public void setNome(String nome){
		this.nome = nome;
	}


}// fim da classe