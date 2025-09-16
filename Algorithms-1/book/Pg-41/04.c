#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Faça um algoritmo que apresente o menu abaixo, enquanto a opção
digitada for diferente de 0.
MENU:
1-Dizer “Oi”
2-Dizer “Olá“
0-SAIR
97
Se o usuário digitar 1, o algoritmo deverá apresentar a mensagem “Oi”. Se
o usuário digitar 2, o algoritmo deve apresentar a mensagem “Olá“. Se o
algoritmo digitar 0, deve terminar.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int op;

  printf("\n\t Mês: \n");

  printf("\n\t 1-Janeiro");
  printf("\n\t 2-Fevereiro");
  printf("\n\t 3-Março");
  printf("\n\t 4-Maio");
  printf("\n\t 5-Abril");
  printf("\n\t 6-Junho");
  printf("\n\t 7-Julho");
  printf("\n\t 8-Agosto");
  printf("\n\t 9-Setembro");
  printf("\n\t 10-Outubro");
  printf("\n\t 11-Novembro");
  printf("\n\t 12-Dezembro");
  printf("\n\t 0-Sair");

  do {

    printf("\n Informe um mês: ");
    scanf("%d", &op);

    switch (op) {

      case 0: {
        printf("Saindo...");
        return 0;
        break;
      }

      case 1: {
        printf("janeiro tem 31 dias!");
        break;
      }

      case 2: {
        printf("Fevereiro tem 28 dias!");
        break;
      }

      case 3: {
        printf("Março tem 31 dias!");
        break;
      }

      case 4: {
        printf("Abril tem 30 dias!");
        break;
      }

      case 5: {
        printf("Maio tem 31 dias!");
        break;
      }

      case 6: {
        printf("Junho tem 30 dias!");
        break;
      }

      case 7: {
        printf("Julho tem 31 dias!");
        break;
      }

      case 8: {
        printf("Agosto tem 31 dias!");
        break;
      }

      case 9: {
        printf("Setembro tem 30 dias!");
        break;
      }

      case 10: {
        printf("Outubro tem 31 dias!");
        break;
      }

      case 11: {
        printf("Novembro tem 30 dias!");
        break;
      }

      case 12: {
        printf("Dezembro tem 31 dias!");
        break;
      }

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while (op != 0);


  return 0;
}
