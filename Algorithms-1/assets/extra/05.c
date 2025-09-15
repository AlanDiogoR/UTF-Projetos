#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  int menu_principal, menu_conversao;
  double valor, resultado;

  printf("Menu Principal:\n");
  printf("1-Conversão de temperatura\n");
  printf("2-Conversão de distância\n");
  printf("Escolha uma opção: ");
  scanf("%d", &menu_principal);

  switch (menu_principal)
  {
  case 1:
    printf("Menu de Conversão de Temperatura:\n");
    printf("1-Converter Celsius para Fahrenheit\n");
    printf("2-Converter Fahrenheit para Celsius\n");
    printf("3-Converter Celsius para Kelvin\n");
    printf("Escolha uma opção: ");
    scanf("%d", &menu_conversao);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    switch (menu_conversao)
    {
    case 1:
      resultado = (9 * valor / 5) + 32;
      printf("%.2lf Celsius = %.2lf Fahrenheit\n", valor, resultado);
      break;
    case 2:
      resultado = 5 * (valor - 32) / 9;
      printf("%.2lf Fahrenheit = %.2lf Celsius\n", valor, resultado);
      break;
    case 3:
      resultado = valor + 273;
      printf("%.2lf Celsius = %.2lf Kelvin\n", valor, resultado);
      break;
    default:
      printf("Opção de conversão de temperatura inválida.\n");
      break;
    }
    break;
  case 2:
    printf("Menu de Conversão de Distância:\n");
    printf("1-Converter km para milhas\n");
    printf("2-Converter milhas para km\n");
    printf("Escolha uma opção: ");
    scanf("%d", &menu_conversao);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    switch (menu_conversao)
    {
    case 1:
      resultado = valor * 0.62137;
      printf("%.2lf km = %.2lf milhas\n", valor, resultado);
      break;
    case 2:
      resultado = valor / 0.62137;
      printf("%.2lf milhas = %.2lf km\n", valor, resultado);
      break;
    default:
      printf("Opção de conversão de distância inválida.\n");
      break;
    }
    break;
  default:
    printf("Opção do menu principal inválida.\n");
    break;
  }

  return 0;
}
