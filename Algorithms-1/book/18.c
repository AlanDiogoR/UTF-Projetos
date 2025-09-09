#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
7. Faça um algoritmo que peça um número positivo maior que 0 e
apresente os valores de 1 a este valor digitado.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i, count;

  printf("\n\t Informar 1 a x com for!");
  printf("\n\t Informe um número inteiro maior que 5: ");
  scanf("%d", &count);

  for ( i = 0; i <= count; i++) {
    printf("\n\t %d", i);
  }


  return 0;
}
