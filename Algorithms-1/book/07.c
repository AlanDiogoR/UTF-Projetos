#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int numero;

  printf("\n\t Exercício 01");

  printf("\nInforme um número inteiro: ");
  scanf("%d", &numero);

  if (numero > 0) {
    printf("\nValor positivo");
  } else if (numero < 0) {
    printf("\nValor negativo");
  } else {
    printf("\nValor neutro");
  }

  return 0;
}
