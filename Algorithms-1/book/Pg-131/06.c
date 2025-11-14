/*
6. Faça um programa que peça 6 números inteiros e, depois, apresente-os
na tela na forma invertida ao que foi digitado. Exemplo, se foi digitado 1 3
2 4 5 9, deve ser apresentado 9 5 4 2 3 1. */

#include <stdio.h>
int main()
{
  int numeros[6], i;

  printf("Digite 6 números inteiros:\n");
  for (i = 0; i < 6; i++)
  {
    printf("Número %d: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  printf("Números na ordem invertida:\n");
  for (i = 5; i >= 0; i--)
  {
    printf("%d\n", numeros[i]);
  }

  return 0;
}
