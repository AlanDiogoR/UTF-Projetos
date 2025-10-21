#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM  6

int main() {
  int vet[TAM];
  int i;

  for (i = 0; i < TAM; i++)
  {
    printf("\nInforme o primeiro número: ");
    scanf("%d", &vet[i]);
  }

  for ( i = 0; i < TAM; i++)
  {
    printf(" |%d| ", vet[i]);
  }

  return 0;
}
