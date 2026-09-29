public class TstInt{

	public static void main(String arg[]){
		Visao visao = new Leitura();
		boolean demo = arg.length > 0 && arg[0].equals("demo");

		IAluno aluno = new Aluno();
		IProf prof = new Prof();
		IConvidado convidado = new Convidado();

		if(demo){
			preencheDemo(aluno, prof, convidado);
		}else{
			preenchePeloTeclado(visao, aluno, prof, convidado);
		}

		ImpDados[] cadastro = new ImpDados[3];
		cadastro[0] = aluno;
		cadastro[1] = prof;
		cadastro[2] = convidado;

		visao.impDados("\n ======== SAIDA PELA INTERFACE ImpDados ========");
		for(int i = 0; i < cadastro.length; i++){
			cadastro[i].printDados();
		}
	}

	private static void preencheDemo(IAluno aluno, IProf prof, IConvidado convidado){
		aluno.setRa(2026001);
		aluno.setCurso("Engenharia de Software");
		aluno.setCpf(123456789);
		aluno.setNome("Ana Souza");
		aluno.getEnder().setRua("Rua das Flores");
		aluno.getEnder().setNum(120);
		aluno.getEnder().getLocal().setCidade("Cornelio Procopio");
		aluno.getEnder().getLocal().setCep("86300-000");
		aluno.getEnder().getLocal().setCodCidade(4106902);

		prof.setSal(8500);
		prof.setTitulo("Mestre");
		prof.setCpf(987654321);
		prof.setNome("Carlos Lima");
		prof.getEnder().setRua("Avenida Universitaria");
		prof.getEnder().setNum(45);
		prof.getEnder().getLocal().setCidade("Cornelio Procopio");
		prof.getEnder().getLocal().setCep("86300-000");

		convidado.setNomeEvento("SECOMP");
		convidado.setDataEvento("29/09/2026");
		convidado.setLocalOrigem("UTFPR-CP");
	}

	private static void preenchePeloTeclado(Visao visao, IAluno aluno, IProf prof, IConvidado convidado){
		visao.impDados("\n ============ DADOS DO ALUNO ==========");
		aluno.setRa(leInt(visao, "\nRA....: "));
		aluno.setCurso(visao.entDados("\nCURSO...: "));
		aluno.setCpf(leInt(visao, "\n CPF - ALUNO...: "));
		aluno.setNome(visao.entDados("\nNOME - ALUNO..: "));
		aluno.getEnder().setNum(leInt(visao, "\n NUMERO- ALUNO...: "));
		aluno.getEnder().setRua(visao.entDados("\nRUA- ALUNO..: "));
		aluno.getEnder().getLocal().setCidade(visao.entDados("\nCIDADE- ALUNO..: "));
		aluno.getEnder().getLocal().setCep(visao.entDados("\nCEP- ALUNO..: "));
		aluno.getEnder().getLocal().setCodCidade(leInt(visao, "\nCOD CIDADE- ALUNO...: "));

		visao.impDados("\n ============ DADOS DO PROFESSOR ==========");
		prof.setSal(leInt(visao, "\nSALARIO - PROF....: "));
		prof.setTitulo(visao.entDados("\nTITULO - PROF ...: "));
		prof.setCpf(leInt(visao, "\n CPF - PROF...: "));
		prof.setNome(visao.entDados("\nNOME - PROF..: "));
		prof.getEnder().setNum(leInt(visao, "\n NUMERO - PROF...: "));
		prof.getEnder().setRua(visao.entDados("\nRUA - PROF..: "));
		prof.getEnder().getLocal().setCidade(visao.entDados("\nCIDADE - PROF..: "));
		prof.getEnder().getLocal().setCep(visao.entDados("\nCEP - PROF..: "));

		visao.impDados("\n ============ DADOS DO CONVIDADO ==========");
		convidado.setNomeEvento(visao.entDados("\nEVENTO...: "));
		convidado.setDataEvento(visao.entDados("\nDATA...: "));
		convidado.setLocalOrigem(visao.entDados("\nORIGEM...: "));
	}

	private static int leInt(Visao visao, String rotulo){
		String texto = visao.entDados(rotulo);
		try{
			return Integer.parseInt(texto.trim());
		}catch(NumberFormatException e){
			visao.impDados("\nValor invalido, usando 0");
			return 0;
		}
	}

}
