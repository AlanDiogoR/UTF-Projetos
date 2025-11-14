#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define TAM 10

int main()
{
  int num[TAM];
  int i = 0;
  int j, n;
  int impares;
  bool repetido;

  srand(time(NULL));

  while (i < TAM)
  {
    n = (rand() % 100);
    repetido = false;

    for (j = 0; j < i; j++)
    {
      if (num[j] == n)
      {
        repetido = true;
        break;
      }
    }

    if (!repetido)
    {
      num[i] = n;
      i++;
    }
  }

  for (i = 0; i < TAM; i++)
  {
    printf("|%d| ", num[i]);

    if (num[i] % 2 != 0)
    {
      impares++;
    }
  }

  for (i = 0; i < TAM; i++)
  {
    if (i % 2 == 0)
    {
      printf("\n%d ", num[i]);
    }
  }

  printf("\nImpares presentes: %d", impares);

  return 0;
}
