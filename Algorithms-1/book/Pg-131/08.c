/*8. Faça um programa que peça 6 valores inteiros. Após digitados os valores,
a ordem deve ser trocada de forma que. o primeiro valor deve ser colocado
na última posição do vetor, o segundo valor deve ser colocado na penúltima
posição e assim por diante. OBS: repare que este exercício é diferente do anterior: no exercício 7, os
valores devem ser colocados nas posições invertidas logo após cada valor
ser digitado. No exercício 8, os valores devem ser trocados apenas depois
que todos eles forem digitados.  e use define para vetor tam*/

#include <stdio.h>
#define TAM 6

int main()
{
  int numeros[TAM], temp;

  printf("Digite %d valores inteiros:\n", TAM);
  for (int i = 0; i < TAM; i++)
  {
    printf("Valor %d: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  // Troca os valores para inverter a ordem
  for (int i = 0; i < TAM / 2; i++)
  {
    temp = numeros[i];
    numeros[i] = numeros[TAM - 1 - i];
    numeros[TAM - 1 - i] = temp;
  }

  printf("Os valores na ordem invertida são:\n");
  for (int i = 0; i < TAM; i++)
  {
    printf("%d\n", numeros[i]);
  }

  return 0;
}
