
/*3. Faça um programa que peça 5 números reais. Depois, o programa deve
apresentar o número maior. */

#include <stdio.h>

int main()
{
  float numero, maior;

  printf("Digite 5 números reais:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ", i + 1);
    scanf("%f", &numero);

    if (i == 0 || numero > maior)
    {
      maior = numero;
    }
  }

  printf("O maior número digitado foi: %.2f\n", maior);

  return 0;
}
