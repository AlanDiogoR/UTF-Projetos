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

  printf("\n\t Monstrodex: \n");

  printf("\n\t 1-Zikachu");
  printf("\n\t 2-Zulbassauro");
  printf("\n\t 3-Zharmander");
  printf("\n\t 0-Sair do Monstrodex");

  do {

    printf("\n Informe uma opçao: ");
    scanf("%d", &op);

    switch (op) {

      case 0: {
        printf("Saindo...");
        return 0;
        break;
      }

      case 1: {
        printf("Monstro elétrico da categoria rato");
        break;
      }

      case 2: {
        printf("Monstro de grama da categoria semente");
        break;
      }

      case 3: {
        printf("Monstro não cadastrado. Há 8900 monstros! Temos que pegar!");
        break;
      }

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while (op != 0);


  return 0;
}
