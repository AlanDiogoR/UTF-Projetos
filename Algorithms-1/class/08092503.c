#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
for, exemplo professora
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;

  printf("\n\t Valor discreto!");

  for ( i = 0; i < 6; i++) {
    printf("\n\t O valor do contador é: %d", i);
  }

  printf("O valor Final da variavial i(contador) é: %d", i);


  return 0;
}
