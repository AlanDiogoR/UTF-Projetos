#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
9. Faça um algoritmo que peça um número inicial e um número final. Em
seguida, deve ser apresentada a contagem do número inicial ao número final.
Suponha que o número inicial é sempre menor que o final.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int n1, n2, i;

  printf("\n\tContar intervalos de números!");
  printf("\n\tInforme um número inicial: ");
  scanf("%d", &n1);
  printf("\n\tInforme um número final maior que o inicial: ");
  scanf("%d", &n2);

  for (i = n1; i <= n2; i++) {
    printf("\n\t%d", i);
  }


  return 0;
}
