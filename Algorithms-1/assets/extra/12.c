#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  int numero, num_invertido, digito1, digito2, digito3;

  printf("Digite um número de 3 dígitos: ");
  scanf("%d", &numero);

  if (numero < 100 || numero > 999)
  {
    printf("O número deve ter 3 dígitos.\n");
    return 1;
  }

  digito1 = numero / 100;        // Centenas
  digito2 = (numero % 100) / 10; // Dezenas
  digito3 = numero % 10;         // Unidades

  num_invertido = digito3 * 100 + digito2 * 10 + digito1;

  printf("Número lido: %d\n", numero);
  printf("Número invertido: %d\n", num_invertido);

  return 0;
}
