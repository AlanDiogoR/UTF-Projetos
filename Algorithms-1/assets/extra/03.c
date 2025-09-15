#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double A, B, C, delta;

  printf("Digite o coeficiente A da equação quadrática: ");
  scanf("%lf", &A);
  printf("Digite o coeficiente B da equação quadrática: ");
  scanf("%lf", &B);
  printf("Digite o coeficiente C da equação quadrática: ");
  scanf("%lf", &C);

  delta = B * B - 4 * A * C;

  printf("O valor do discriminante (delta) é: %.2lf\n", delta);

  return 0;
}
