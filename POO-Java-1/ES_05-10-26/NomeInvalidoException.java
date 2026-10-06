public class NomeInvalidoException extends Exception{

	public NomeInvalidoException(){
		System.out.println("\n Gerou um NOVO Objt. do tipo NomeInvalidoException");
	}

	public void impErroNomeInvalido(){
		System.out.println("\n O nome não pode ser vazio");
	}

}
