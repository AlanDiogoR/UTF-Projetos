#include <stdio.h>
#define KM_TO_MI 0.621371
#define MI_TO_KM 1.60934

void exibeMenu()
{
  printf("MENU:\n");
  printf("1 - Converter quilômetros em milhas\n");
  printf("2 - Converter milhas em quilômetros\n");
  printf("0 - SAIR\n");
  printf("Escolha uma opção: ");
}

double converterKmParaMi(double km)
{
  return km * KM_TO_MI;
}

double converterMiParaKm(double mi)
{
  return mi * MI_TO_KM;
}

int main()
{
  int opcao;
  double distancia, resultado;

  do
  {
    exibeMenu();
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite a distância em quilômetros: ");
      scanf("%lf", &distancia);
      resultado = converterKmParaMi(distancia);
      printf("%.2f km é igual a %.2f milhas.\n", distancia, resultado);
      break;
    case 2:
      printf("Digite a distância em milhas: ");
      scanf("%lf", &distancia);
      resultado = converterMiParaKm(distancia);
      printf("%.2f milhas é igual a %.2f km.\n", distancia, resultado);
      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}
