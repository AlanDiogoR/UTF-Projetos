#include <stdio.h>
#define TAM 6

int main() {
  int i;

  float preco[TAM];
  float maior;

  for ( i = 0; i < TAM; i++)
  {
   printf("Informe o preço do produto %d: ", i + 1);
   scanf("%f", &preco[i]);
  }

}
