#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
4. Faça um algoritmo que apresente os valores de 15 a 5.
*/


int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Decrescente de 15 a 5");

  for (i = 15; i >= 5; i--) {
    printf("\n\t %d", i);
  }


  return 0;
}

