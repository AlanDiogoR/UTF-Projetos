#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
8. Faça um algoritmo que peça um número menor que 10 e apresente os
valores deste número digitado a 10. Por exemplo, se o usuário digitar 8, deverá
apresentar os valores: 8, 9 e 10.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i, count;

  printf("\n\t Informar x a 10 com for!");
  printf("\n\t Informe um número inteiro menor que 10: ");
  scanf("%d", &count);

  for ( i = count; i <= 10; i++) {
    printf("\n\t %d", i);
  }


  return 0;
}
