#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double aplicacao_mensal, taxa, valor_acumulado;
  int numero_meses;

  printf("Digite o valor da aplicação mensal: ");
  scanf("%lf", &aplicacao_mensal);
  printf("Digite a taxa de juros (ex: 0.01 para 1%% ao mês): ");
  scanf("%lf", &taxa);
  printf("Digite o número de meses: ");
  scanf("%d", &numero_meses);

  // Formula: valoracumulado = ((pow((1 + i), n) - 1) / i) * P
  valor_acumulado = ((pow((1 + taxa), numero_meses) - 1) / taxa) * aplicacao_mensal;

  printf("\nO valor acumulado na poupança é: %.2lf\n", valor_acumulado);

  return 0;
}
