public class Endereco implements IEndereco{

	private String rua = "";
	private int num = 0;
	private Local local = new Local();
	
	public String getRua(){
		return rua;
	}
	
	public int getNum(){
		return num;
	}

	public void setRua(String rua){
		this.rua = rua;
	}
	
	public void setNum(int num){
		this.num = num;
	}

	public Local getLocal(){
		return local;
	}

	public void setLocal(Local local){
		this.local = local;
	}

}