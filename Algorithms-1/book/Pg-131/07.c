/*7. Faça um programa que peça 6 valores inteiros, mas o primeiro valor deve
ser colocado na última posição do vetor, o segundo valor deve ser colocado
na penúltima posição e assim por diante.*/

#include <stdio.h>

int main()
{
  int numeros[6];

  printf("Digite 6 valores inteiros:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("Valor %d: ", i + 1);
    scanf("%d", &numeros[5 - i]); // Armazena na posição invertida
  }

  printf("Os valores na ordem invertida são:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("%d\n", numeros[i]);
  }

  return 0;
}
