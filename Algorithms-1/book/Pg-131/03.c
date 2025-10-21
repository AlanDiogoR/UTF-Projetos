#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 5

int main()  {
  int vet[TAM];
  int i, maior;

  maior = 0;

  for ( i = 0; i < TAM; i++)
  {
    printf("\n\tInforme o numero: ");
    scanf("%d", &vet[i]);
  }

  for ( i = 0; i < TAM; i++)
  {
    printf("|%d| ", vet[i]);

    if (vet[i] > maior)
    {
      maior = vet[i];
    }

  }

  printf("\nMaior: %d", maior);

  return 0;

}
