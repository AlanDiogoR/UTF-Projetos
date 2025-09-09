#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
1. Faça um algoritmo que apresente os valores de 1 a 10.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Informar 0 10 com for!");

  for ( i = 1; i < 11; i++) {
    printf("\n\t %d", i);
  }


  return 0;
}
