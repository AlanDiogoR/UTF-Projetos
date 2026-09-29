public class TstHer{

	public static void main(String arg[]){//classLoader
		
		Leitura l = new Leitura();
	
		Aluno a1 = new Aluno();
		
		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Aluno(); //Coersão
		
		//a1.setCpf(16);
		
		p2.setRa(13);
		
		
		p1.printDados();
		p2.printDados();

		//a1.printDados();
		
		
		
		
//Prof pr1 = new Prof();
		
/*
		l.entDados("\n ============ DADOS DO ALUNO <Press a key> ==========\n");

		a1.setRa(Integer.parseInt(l.entDados("\nRA....: "))); //Aluno
		a1.setCurso(l.entDados("\nCURSO...: ")); //Aluno
		
		a1.setCpf(Integer.parseInt(l.entDados("\n CPF - ALUNO...: ")));//Pessoa
		a1.setNome(l.entDados("\nNOME - ALUNO..: "));
		
		a1.getEnder().setNum(Integer.parseInt(l.entDados("\n NUMERO- ALUNO...: "))); //Reflections
		a1.getEnder().setRua(l.entDados("\nRUA- ALUNO..: "));//Reflections		
		
		
		System.out.println("\nRA- ALUNO...: "+      a1.getRa()); //ALUNO
		System.out.println("\nCURSO- ALUNO...:"+    a1.getCurso()); //ALUNO 
		System.out.println("\nCPF - ALUNO...: "+    a1.getCpf()); //Pessoa
		System.out.println("\nNOME - ALUNO...: "+   a1.getNome());	//Pessoa		
		System.out.println("\nRUA - ALUNO...: "+    a1.getEnder().getRua());//Pessoa		
		System.out.println("\nNUMERO - ALUNO...: "+ a1.getEnder().getNum());//Pessoa	
		
				l.entDados("\n ============ DADOS DO PROFESSOR <Press a key> ==========\n");

		pr1.setSal(Integer.parseInt(l.entDados("\nSALARO - PROF....: "))); //Prof
		pr1.setTitulo(l.entDados("\nTITULO - PROF ...: ")); //Prof
		
		pr1.setCpf(Integer.parseInt(l.entDados("\n CPF - PROF...: ")));//Pessoa
		pr1.setNome(l.entDados("\nNOME - PROF..: "));
		
		pr1.getEnder().setNum(Integer.parseInt(l.entDados("\n NUMERO - PROF...: "))); //Reflections
		pr1.getEnder().setRua(l.entDados("\nRUA - PROF..: "));//Reflections		
		
		
		System.out.println("\nRA - PROF...: "+    pr1.getSal()); //PROF
		System.out.println("\nCURSO- PROF...:"+   pr1.getTitulo()); //PROF 
		System.out.println("\nCPF - PROF...: "+   pr1.getCpf()); //Pessoa
		System.out.println("\nNOME - PROF...: "+  pr1.getNome());	//Pessoa		
		System.out.println("\nRUA - PROF...: "+   pr1.getEnder().getRua());//Pessoa		
		System.out.println("\nNUMERO - PROF...: "+pr1.getEnder().getNum());//Pessoa	
*/
	}//fim do main

}