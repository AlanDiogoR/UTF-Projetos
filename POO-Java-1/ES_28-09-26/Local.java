public class Local implements ILocal{

	private String cidade = "";
	private String cep = "";
	private int codCidade = 0;

	public String getCidade(){
		return cidade;
	}

	public void setCidade(String cidade){
		this.cidade = cidade;
	}

	public String getCep(){
		return cep;
	}

	public void setCep(String cep){
		this.cep = cep;
	}

	public int getCodCidade(){
		return codCidade;
	}

	public void setCodCidade(int codCidade){
		this.codCidade = codCidade;
	}

}
