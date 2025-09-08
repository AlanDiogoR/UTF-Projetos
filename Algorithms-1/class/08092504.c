#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
for, exemplo professora - decremnto
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Valor discreto!");

  for ( i = 100; i >= 0; i--) {
    printf("\n\t %d", i);
  }

  printf("O valor Final da variavial i(contador) é: %d", i);


  return 0;
}
