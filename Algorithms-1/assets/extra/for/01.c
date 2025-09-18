#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Portuguese");

  char conceito;

  printf("Informe o conceito anual (A/B/C/D): ");
  scanf(" %c", &conceito);

  switch (conceito)
  {
  case 'A':
  case 'a':
    printf("Conhecimento Pleno\n");
    break;
  case 'B':
  case 'b':
    printf("Conhecimento Parcialmente Pleno\n");
    break;
  case 'C':
  case 'c':
    printf("Conhecimento Suficiente\n");
    break;
  case 'D':
  case 'd':
    printf("Conhecimento Insuficiente\n");
    break;
  default:
    printf("Conceito Inválido\n");
    break;
  }
  return 0;
}
