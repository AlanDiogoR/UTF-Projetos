#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  int A, B, C;
  double R, S, D;

  printf("Digite o valor inteiro positivo A: ");
  scanf("%d", &A);
  printf("Digite o valor inteiro positivo B: ");
  scanf("%d", &B);
  printf("Digite o valor inteiro positivo C: ");
  scanf("%d", &C);

  R = pow((A + B), 2);
  S = pow((B + C), 2);
  D = (R + S) / 2;

  printf("O valor da expressão D é: %.2lf\n", D);

  return 0;
}
