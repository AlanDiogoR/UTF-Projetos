/*

1. Faça um programa que peça 6 valores inteiros e os apresente na tela logo
após serem digitados.
*/

#include <stdio.h>

int main()
{
  int valores[6];

  for (int i = 0; i < 6; i++)
  {
    printf("Digite o %dº valor inteiro: ", i + 1);
    scanf("%d", &valores[i]);
  }

  printf("Os valores digitados foram:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("%d\n", valores[i]);
  }
  return 0;
}
