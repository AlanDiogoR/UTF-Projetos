/*
5. Faça um programa que peça 5 números inteiros e, no final, troque a
ordem do primeiro número com a do último número digitado. */

#include <stdio.h>

int main()
{
  int numeros[5], temp;

  printf("Digite 5 números inteiros:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  // Troca o primeiro número com o último
  temp = numeros[0];
  numeros[0] = numeros[4];
  numeros[4] = temp;

  printf("Números após a troca:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", numeros[i]);
  }

  return 0;
}
