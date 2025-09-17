#include <stdio.h>
#include <locale.h>

/*
Faça um algoritmo que peça o semestre em que está cursando a faculdade.
a. Se estiver no sétimo período ou superior, o algoritmo deve apresentar o
menu:
   1 - matricular na disciplina de Jogos Digitais;
   2 - Matricular na disciplina de Design de Jogos;
   3 - Matricular na disciplina de Realidade Virtual.
   i. Se a opção for 1, apresentar a mensagem: “Jogos Digitais confirmado”;
   ii. Se a opção for 2, apresentar a mensagem: “Design confirmado”;
   iii. Se a opção for 3, apresentar a mensagem: “RV confirmado”.
b. Caso não esteja pelo menos no sétimo período, apresentar a mensagem:
   “Você ainda não pode se matricular em disciplinas optativas”.
*/

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int semestre, opcao;

  printf("\n\t Matrícula em Disciplinas Optativas\n");

  printf("\nInforme o semestre em que está cursando: ");
  scanf("%d", &semestre);

  if (semestre >= 7)
  {
    printf("\nVocê pode se matricular em disciplinas optativas.");
    printf("\nEscolha uma das opções abaixo:\n");
    printf("1 - Jogos Digitais\n");
    printf("2 - Design de Jogos\n");
    printf("3 - Realidade Virtual\n");

    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("\nJogos Digitais confirmado!");
      break;
    case 2:
      printf("\nDesign confirmado!");
      break;
    case 3:
      printf("\nRV confirmado!");
      break;
    default:
      printf("\nOpção inválida!");
    }
  }
  else
  {
    printf("\nVocê ainda não pode se matricular em disciplinas optativas.");
  }

  return 0;
}
