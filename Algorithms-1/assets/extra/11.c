#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double valor_dolar, taxa_dolar, icms_percentual, lucro_percentual;
  double valor_reais_sem_impostos, valor_icms, valor_lucro, valor_total_reais;

  printf("Digite o valor da compra em dólares: ");
  scanf("%lf", &valor_dolar);
  printf("Digite a taxa do dólar no dia da compra (ex: 5.00): ");
  scanf("%lf", &taxa_dolar);
  printf("Digite o percentual de ICMS (ex: 18 para 18%%): ");
  scanf("%lf", &icms_percentual);
  printf("Digite o percentual de lucro da empresa (ex: 20 para 20%%): ");
  scanf("%lf", &lucro_percentual);

  valor_reais_sem_impostos = valor_dolar * taxa_dolar;

  valor_total_reais = valor_reais_sem_impostos / (1 - (icms_percentual / 100) - (lucro_percentual / 100));

  printf("\nO valor a ser pago em reais é: %.2lf\n", valor_total_reais);

  return 0;
}
