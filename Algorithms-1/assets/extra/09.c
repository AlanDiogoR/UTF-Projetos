#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  int valor_reais;
  int notas100, notas50, notas10, notas5, notas1;

  printf("Digite um valor em reais: ");
  scanf("%d", &valor_reais);

  printf("Valor lido: %d reais\n", valor_reais);
  printf("Notas necessárias:\n");

  notas100 = valor_reais / 100;
  valor_reais %= 100;
  printf("%d nota(s) de 100 reais\n", notas100);

  notas50 = valor_reais / 50;
  valor_reais %= 50;
  printf("%d nota(s) de 50 reais\n", notas50);

  notas10 = valor_reais / 10;
  valor_reais %= 10;
  printf("%d nota(s) de 10 reais\n", notas10);

  notas5 = valor_reais / 5;
  valor_reais %= 5;
  printf("%d nota(s) de 5 reais\n", notas5);

  notas1 = valor_reais / 1;
  valor_reais %= 1;
  printf("%d nota(s) de 1 real\n", notas1);

  return 0;
}
