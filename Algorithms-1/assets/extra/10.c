#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double distancia, volume_combustivel, consumo_medio;

  printf("Digite a distância total percorrida (Km): ");
  scanf("%lf", &distancia);
  printf("Digite o volume de combustível consumido (litros): ");
  scanf("%lf", &volume_combustivel);

  if (volume_combustivel <= 0)
  {
    printf("O volume de combustível deve ser maior que zero.\n");
    return 1;
  }

  consumo_medio = distancia / volume_combustivel;

  printf("O consumo médio do automóvel é: %.2lf Km/l\n", consumo_medio);

  return 0;
}
