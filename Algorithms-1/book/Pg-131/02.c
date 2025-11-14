/*2. Faça um programa que peça 6 valores inteiros e, depois, apresente-os na
tela. sem vetor */

#include <stdio.h>
int main()
{
  int valor;

  printf("Digite 6 valores inteiros:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("Valor %d: ", i + 1);
    scanf("%d", &valor);
    printf("Você digitou: %d\n", valor);
  }

  return 0;
}
