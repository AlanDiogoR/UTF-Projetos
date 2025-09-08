#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
for, exemplo professora - pares
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Valor discreto!");

  for ( i = 0; i < 50; i++) {
    if(i %5 == 0) {
      printf("\n\t Numeros pares de 0 a 50: %d", i);
    }
  }

  printf("O valor Final da variavial i(contador) é: %d", i);


  return 0;
}
