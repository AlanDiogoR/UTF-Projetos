#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

int main() {
  int i;
  int VET1[TAM];
  srand(time(NULL));

  for ( i = 0; i < TAM; i++)
  {
    VET1[i] = 10 - rand() % 20;
  }

  for ( i = 0; i < TAM; i++)
  {
    printf("%d", VET1[i]);
  }

  return 0;
}
