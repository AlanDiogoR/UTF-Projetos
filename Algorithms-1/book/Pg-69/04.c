#include <stdio.h>
#include <locale.h>

/*
Imagine um problema de gerenciamento de fila de um banco que emite senhas
para aguardar na fila. Faça um algoritmo que:
a. Peça o número da senha para o usuário;
b. Apresente o menu 1-Prioridade; 2-Aposentado; 3-Comum.
c. Se o número da senha for menor que 100, o algoritmo deve apresentar a
mensagem: “aguarde para ser atendido”.
d. Senão, o algoritmo deve apresentar uma mensagem, conforme a opção:
   i. Se for 1, “Você será reagendado para amanhã”;
   ii. Se for 2, “Você será reagendado para depois de amanhã”;
   iii. Se for 3, “Você deve tentar outro dia”.
*/

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int senha, opcao;

  printf("\n\tGerenciamento de Fila do Banco\n");

  printf("\nInforme o número da sua senha: ");
  scanf("%d", &senha);

  printf("\nEscolha uma das opções:\n");
  printf("1 - Prioridade\n");
  printf("2 - Aposentado\n");
  printf("3 - Comum\n");
  printf("Digite sua opção: ");
  scanf("%d", &opcao);

  if (senha < 100)
  {
    printf("\nAguarde para ser atendido.");
  }
  else
  {
    switch (opcao)
    {
    case 1:
      printf("\nVocê será reagendado para amanhã.");
      break;
    case 2:
      printf("\nVocê será reagendado para depois de amanhã.");
      break;
    case 3:
      printf("\nVocê deve tentar outro dia.");
      break;
    default:
      printf("\nOpção inválida!");
    }
  }

  return 0;
}
