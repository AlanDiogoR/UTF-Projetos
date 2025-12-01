

#include <stdio.h>

void valores()
{
  int a, b, c, d;
  int maior, menor;

  printf("Digite quatro valores inteiros:\n");
  scanf("%d %d %d %d", &a, &b, &c, &d);

  // Encontrar o maior valor
  maior = a;
  if (b > maior)
    maior = b;
  if (c > maior)
    maior = c;
  if (d > maior)
    maior = d;

  // Encontrar o menor valor
  menor = a;
  if (b < menor)
    menor = b;
  if (c < menor)
    menor = c;
  if (d < menor)
    menor = d;

  printf("O maior valor é: %d\n", maior);
  printf("O menor valor é: %d\n", menor);
}

int main()
{
  valores();
  return 0;
}
