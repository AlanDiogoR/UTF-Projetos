/*
01) Faça um programa em Linguagem C que leia um vetor NUMERO de 15 posições sem
números repetidos e o apresente na tela. A seguir, apresentar a quantidade de valores do
vetor negativos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15

int main()
{
  int numero[TAM], i, j, valor, repetido, cont_negativos = 0;

  for (i = 0; i < TAM; i++)
  {
    do
    {
      repetido = 0;
      printf("Digite o valor para a posicao [%d]: ", i);
      scanf("%d", &valor);

      for (j = 0; j < i; j++)
      {
        if (numero[j] == valor)
        {
          repetido = 1;
          printf("Valor repetido! Digite outro numero.\n");
          break;
        }
      }
    } while (repetido);

    numero[i] = valor;

    // Conta se o valor e negativo
    if (valor < 0)
    {
      cont_negativos++;
    }
    }

  return 0;
}
