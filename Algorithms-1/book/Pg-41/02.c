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

  char op;

  printf("\n\t Monstrodex: \n");

  printf("\n\t A- Avião");
  printf("\n\t B- Carro");
  printf("\n\t C- Cruzeiro");
  printf("\n\t 0-Sair");

  do {

    printf("\n Informe uma opçao: ");
    scanf(" %c", &op);

    switch (op) {

      case '0': {
        printf("Saindo...");
        return 0;
        break;
      }

      case 'A':
      case 'a': {
        printf("É mais rápido!");
        break;
      }

      case 'B':
      case 'b': {
        printf("É mais barato!");
        break;
      }
      case 'c':
      case 'C': {
        printf("É mais bonito!");
        break;
      }

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while (op != '0');


  return 0;
}
