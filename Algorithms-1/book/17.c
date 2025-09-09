#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
6. Faça um algoritmo que apresente os valores ímpares de 1 a 10.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Ímares de 1 a 10!");

  for ( i = 1; i <= 10; i++) {
    if(i %2 != 0) {
      printf("\n\t Numeros ímpares de 1 a 10: %d", i);
    }
  }

  return 0;
}
