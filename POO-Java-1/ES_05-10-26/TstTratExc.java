public class TstTratExc{
	
	public static void main(String arg[]){
	
		Leitura l = new Leitura();
		
		Pessoa p1 = new Pessoa();
		
		try{
			p1.setCpf(Integer.parseInt(l.entDados("\nCPF...: ")));
			p1.setNome(l.entDados("\nNOME..: "));
			System.out.println("\nCPF..: "+ p1.getCpf());
			System.out.println("\nNOME..: "+ p1.getNome());					
		}
		
		catch(CpfPeqException cpe){
			cpe.impErroCpfPeq();
		}
		
		catch(CpfGrdException cge){
			cge.impErroCpfGrd();
		}		

		catch(NumberFormatException nfe){
			System.out.println("\nO CPF deve ser um número inteiro");
		}	

		catch(NomePeqException npe){
			npe.impErroNomePeq();
		}		
		
		
	
	}

}