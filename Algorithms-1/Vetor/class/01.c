#include <stdio.h>
#define TAM 6

int main() {
  int i;

  float preco[TAM];
  float maior, p;

  for ( i = 0; i < TAM; i++)
  {
   printf("Informe o preço do produto %d: ", i + 1);
   scanf("%f", &preco[i]);
  }

  for ( i = 0; i < TAM; i++)
  {
    printf("%f", preco[1]);
  }

  for ( i = 0; i < TAM; i++)
  {
    if ( i == 0 || preco[i] > maior) {
      maior = preco [i];
      p = i;
    }
  }

  printf("\n \t O maior preco %.2f está na posiçao: %d ", maior, p);

}
