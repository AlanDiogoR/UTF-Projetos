/*
4. Faça um programa que peça 5 números reais. Depois, o programa deve
apresentar o número menor.*/

#include <stdio.h>
int main()
{
  float numero, menor;

  printf("Digite 5 números reais:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("Número %d: ", i + 1);
    scanf("%f", &numero);

    if (i == 0 || numero < menor)
    {
      menor = numero;
    }
  }

  printf("O menor número digitado foi: %.2f\n", menor);

  return 0;
}
