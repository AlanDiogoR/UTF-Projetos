#include <stdio.h>
#include <string.h>
#define max 100
struct proprietarioProps{
  char nome[50];
  char telefone[15];
};

struct veiculoProps {
  char placa[10];
  char modelo[30];
  int ano;
  struct proprietarioProps dono;
};
 struct contaProps {
  char numeroConta[20];
  char titular[50];
  float saldo;
 };

struct produtoProps {
  char nome[50];
  char codigo[20];
  float preco;
  int quantidade;
};

 

int main() {
  int opcao;

  do  
  {
    Printf("Menu de opcoes:\n");
    Printf("1. Cadastrar veiculo\n");
    Printf("2. Cadastrar conta\n");
    Printf("3. Cadastrar produto\n");
    Printf("4. Sair\n");
    Printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
  } while (opcao < 1 || opcao > 4);

  switch (opcao) {
    case 1: {
      struct veiculoProps veiculo;

      Printf("Digite a placa do veiculo: ");
      scanf("%s", veiculo.placa);
      Printf("Digite o modelo do veiculo: ");
      scanf("%s", veiculo.modelo);
      Printf("Digite o ano do veiculo: ");
      scanf("%d", &veiculo.ano);
      Printf("Digite o nome do proprietario: ");
      scanf("%s", veiculo.dono.nome);
      Printf("Digite o telefone do proprietario: ");
      scanf("%s", veiculo.dono.telefone);

      Printf("\nDados do Veiculo:\n");
      Printf("Placa: %s\n", veiculo.placa);
      Printf("Modelo: %s\n", veiculo.modelo);
      Printf("Ano: %d\n", veiculo.ano);
      Printf("Proprietario: %s\n", veiculo.dono.nome);
      Printf("Telefone: %s\n", veiculo.dono.telefone);
      break;
    }

    case 2:{
      struct contaProps conta;

      Printf("Digite o numero da conta: ");
      scanf("%s", conta.numeroConta);
      Printf("Digite o nome do titular: ");
      scanf("%s", conta.titular);
      Printf("Digite o saldo da conta: ");
      scanf("%f", &conta.saldo);
      Printf("\nDados da Conta:\n");
      Printf("Numero da Conta: %s\n", conta.numeroConta);
      Printf("Titular: %s\n", conta.titular);
      Printf("Saldo: %.2f\n", conta.saldo);

      break;
    }

    case 3:{
      struct produtoProps produto;
      Printf("Digite o nome do produto: ");
      scanf("%s", produto.nome);
      Printf("Digite o codigo do produto: ");
      scanf("%s", produto.codigo);
      Printf("Digite o preco do produto: ");
      scanf("%f", &produto.preco);
      Printf("Digite a quantidade do produto: ");
      scanf("%d", &produto.quantidade);
      Printf("\nDados do Produto:\n");
      Printf("Nome: %s\n", produto.nome);
      Printf("Codigo: %s\n", produto.codigo);
      Printf("Preco: %.2f\n", produto.preco);
      Printf("Quantidade: %d\n", produto.quantidade);
      break;
    }

    case 4:
      Printf("Saindo do programa.\n");
      break;
    
    default:
      Printf("Opcao invalida.\n");
      break;

  }
  

  return 0;
}

