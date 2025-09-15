#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double valor_prestacao, taxa_juros, tempo_atraso_meses, valor_atualizado;

  printf("Digite o valor da prestação: ");
  scanf("%lf", &valor_prestacao);
  printf("Digite a taxa de juros mensal (ex: 2.5 para 2.5%%): ");
  scanf("%lf", &taxa_juros);
  printf("Digite o tempo de atraso em meses: ");
  scanf("%lf", &tempo_atraso_meses);

  valor_atualizado = valor_prestacao + (valor_prestacao * (taxa_juros / 100) * tempo_atraso_meses);

  printf("\nO valor atualizado da prestação é: %.2lf\n", valor_atualizado);

  return 0;
}
