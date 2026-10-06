public class TstTratExc{
	
	public static void main(String arg[]){
	
		Leitura l = new Leitura();
		
		Pessoa p1 = new Pessoa();
		
		try{
			p1.setCpf(Integer.parseInt(l.entDados("\nCPF..: ")));
		}
		
		catch(CpfPeqException cpe){
			cpe.impErroCpfPeq();
		}

		catch(NumberFormatException nfe){
			System.out.println("\nO CPF deve ser um número inteiro");
		}		
		
		System.out.println("\nCPF..: "+ p1.getCpf());
	
	}

}