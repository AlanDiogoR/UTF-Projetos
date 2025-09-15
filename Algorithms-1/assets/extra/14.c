#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double taxa_fixa_dia, taxa_km_rodado;
  int numero_dias, km_rodados;
  double valor_total_aluguel, valor_desconto;

  printf("Digite a taxa fixa por dia: ");
  scanf("%lf", &taxa_fixa_dia);
  printf("Digite a taxa por km rodado: ");
  scanf("%lf", &taxa_km_rodado);
  printf("Digite o número de dias de aluguel: ");
  scanf("%d", &numero_dias);
  printf("Digite o número de quilômetros rodados: ");
  scanf("%d", &km_rodados);

  valor_desconto = taxa_fixa_dia * numero_dias * 0.10; // 10% de desconto na taxa fixa
  valor_total_aluguel = (taxa_fixa_dia * numero_dias) - valor_desconto + (taxa_km_rodado * km_rodados);

  printf("\nValor total do aluguel: %.2lf\n", valor_total_aluguel);
  printf("Valor do desconto: %.2lf\n", valor_desconto);
  printf("Número de dias: %d\n", numero_dias);
  printf("Quilometragem rodada: %d km\n", km_rodados);

  return 0;
}
