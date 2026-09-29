public interface IPessoa extends ImpDados{

	int getCpf();
	void setCpf(int cpf);

	String getNome();
	void setNome(String nome);

	Endereco getEnder();
	void setEnder(Endereco ender);

}
