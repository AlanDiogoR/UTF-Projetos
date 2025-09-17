#include <stdio.h>
#include <locale.h>

/*
Apresente o menu: 1-Conversão de temperatura; 2-Conversão de distância.
Se opção 1: menu de temperatura:
  1 - Converter Celsius para Farenheit;
  2 - Converter Farenheit para Celsius;
  3 - Converter Celsius para Kelvin.
Se opção 2: menu de distância:
  1 - Converter km para milhas;
  2 - Converter milhas para km.
Fórmulas:
  Farenheit = (9*Celsius/5) + 32
  Celsius = 5*(Farenheit-32)/9
  Kelvin = Celsius + 273
  Milha = km * 0.62137
  Km = milha / 0.62137
*/

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int menu, opcao;
  double valor, resultado;

  printf("\nMenu:\n1 - Conversão de temperatura\n2 - Conversão de distância\n");
  printf("Escolha uma opção: ");
  scanf("%d", &menu);

  if (menu == 1)
  {
    printf("\nMenu - Conversão de temperatura:\n");
    printf("1 - Converter Celsius para Farenheit\n");
    printf("2 - Converter Farenheit para Celsius\n");
    printf("3 - Converter Celsius para Kelvin\n");
    printf("Escolha a opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
      printf("Informe a temperatura em Celsius: ");
      scanf("%lf", &valor);
      resultado = (9.0 * valor / 5.0) + 32.0;
      printf("Resultado: %.2f °F\n", resultado);
    }
    else if (opcao == 2)
    {
      printf("Informe a temperatura em Farenheit: ");
      scanf("%lf", &valor);
      resultado = 5.0 * (valor - 32.0) / 9.0;
      printf("Resultado: %.2f °C\n", resultado);
    }
    else if (opcao == 3)
    {
      printf("Informe a temperatura em Celsius: ");
      scanf("%lf", &valor);
      resultado = valor + 273.0;
      printf("Resultado: %.2f K\n", resultado);
    }
    else
    {
      printf("Opção inválida no menu de temperatura.\n");
    }
  }
  else if (menu == 2)
  {
    printf("\nMenu - Conversão de distância:\n");
    printf("1 - Converter km para milhas\n");
    printf("2 - Converter milhas para km\n");
    printf("Escolha a opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
      printf("Informe a distância em km: ");
      scanf("%lf", &valor);
      resultado = valor * 0.62137;
      printf("Resultado: %.4f milhas\n", resultado);
    }
    else if (opcao == 2)
    {
      printf("Informe a distância em milhas: ");
      scanf("%lf", &valor);
      resultado = valor / 0.62137;
      printf("Resultado: %.4f km\n", resultado);
    }
    else
    {
      printf("Opção inválida no menu de distância.\n");
    }
  }
  else
  {
    printf("Opção de menu inválida.\n");
  }

  return 0;
}
