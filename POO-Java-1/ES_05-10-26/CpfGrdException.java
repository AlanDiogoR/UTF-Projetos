public class CpfGrdException extends Exception{

	public CpfGrdException(){
		System.out.println("\n Gerou um NOVO Objt. do tipo CpfGrdException");
	}
	
	public void impErroCpfGrd(){
		System.out.println("\n O CPF deve ser menor que 100");	
	}

}