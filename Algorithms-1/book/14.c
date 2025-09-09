#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
3. Faça um algoritmo que apresente os valores de 5 a 15.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t 5 a 15 com for!");

  for ( i = 5; i < 16; i++) {
    printf("\n\t %d", i);
  }


  return 0;
}
