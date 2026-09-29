public class Convidado implements IConvidado{

	private String localOrigem;
	private String dataEvento;
	private String nomeEvento;

	public Convidado(){
		System.out.println("\n Construtor Default de Convidado");
		localOrigem = "";
		dataEvento = "";
		nomeEvento = "";
	}

	public void printDados(){
		System.out.println("\n\t printDados da classe Convidado");
		System.out.println("\tEVENTO: "+nomeEvento);
		System.out.println("\tDATA: "+dataEvento);
		System.out.println("\tORIGEM: "+localOrigem);
	}

	public String getLocalOrigem(){
		return localOrigem;
	}

	public void setLocalOrigem(String localOrigem){
		this.localOrigem = localOrigem;
	}

	public String getDataEvento(){
		return dataEvento;
	}

	public void setDataEvento(String dataEvento){
		this.dataEvento = dataEvento;
	}

	public String getNomeEvento(){
		return nomeEvento;
	}

	public void setNomeEvento(String nomeEvento){
		this.nomeEvento = nomeEvento;
	}

}
