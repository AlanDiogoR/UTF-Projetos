#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double L1, L2, L3, T, area;

  printf("Digite o comprimento do lado 1 do triângulo: ");
  scanf("%lf", &L1);
  printf("Digite o comprimento do lado 2 do triângulo: ");
  scanf("%lf", &L2);
  printf("Digite o comprimento do lado 3 do triângulo: ");
  scanf("%lf", &L3);

  T = (L1 + L2 + L3) / 2;
  area = sqrt(T * (T - L1) * (T - L2) * (T - L3));

  printf("A área do triângulo é: %.2lf\n", area);

  return 0;
}
