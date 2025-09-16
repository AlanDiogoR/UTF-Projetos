#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

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

  printf("\n\t Calculos: \n");

  printf("\n\t 1-Calcular a área de um retângulo!");
  printf("\n\t 2-Calcular a área de um círculo!");
  printf("\n\t 3-Calcular a área de um triângulo.");
  printf("\n\t 0-Sair ");

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
        float area, altura, base;

        printf("\n\tCalculo a area do retangulo!\n");

        printf("Informe a altura: \n");
        scanf("%f", &altura);
        printf("Informe a base: \n");
        scanf("%f", &base);

        area = altura * base;

        printf("\n A area do retângulo é: %2.f");
        break;
      }

      case 2: {
        float area, raio;

        printf("\n\tCalculo a area do círculo!\n");

        printf("Informe o raio: \n");
        scanf("%f", &raio);

        area = M_PI * pow(raio, 2);

        printf("\n A area do círculo é: %2.f");
        break;
      }

      case 3: {
        float area, altura, base;

        printf("\n\tCalculo a area do triângulo!\n");

        printf("Informe a altura: \n");
        scanf("%f", &altura);
        printf("Informe a base: \n");
        scanf("%f", &base);

        area = (altura / 2) * base;

        printf("\n A area do triângulo é: %2.f");
        break;
      }

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while (op != 0);


  return 0;
}
