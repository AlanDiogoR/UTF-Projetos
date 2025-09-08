#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
for, exemplo professora - soma
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i, qtde, soma;

  qtde = 0;
  soma = 0;

  printf("\n\t Valor discreto!");

  for ( i = 0; i < 101; i++) {

    if (i % 2 == 0) {
      soma = soma + i;
    }

    printf("\n\t A soma dos números pares é: %d", soma);

  }

  printf("O valor Final da variavial i(contador) é: %d", i);


  return 0;
}
