#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
2. Faça um algoritmo que apresente os valores de 10 a 1.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Descrescente de 10!\n");

  for ( i = 10; i > 0; i--) {
    printf("\n\t%d", i);
  }


  return 0;
}
