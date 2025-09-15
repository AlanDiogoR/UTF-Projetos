#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  int idade_dias, anos, meses, dias;

  printf("Digite a idade da pessoa em dias: ");
  scanf("%d", &idade_dias);

  anos = idade_dias / 365;
  dias = idade_dias % 365;
  meses = dias / 30;
  dias = dias % 30;

  printf("A idade expressa em anos, meses e dias é: %d anos, %d meses e %d dias.\n", anos, meses, dias);

  return 0;
}
