#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  int total_prestacoes, prestacoes_pagas;
  double valor_prestacao_atual, total_pago, saldo_devedor;

  printf("Digite o número total de prestações: ");
  scanf("%d", &total_prestacoes);
  printf("Digite a quantidade de prestações pagas: ");
  scanf("%d", &prestacoes_pagas);
  printf("Digite o valor atual da prestação: ");
  scanf("%lf", &valor_prestacao_atual);

  total_pago = prestacoes_pagas * valor_prestacao_atual;
  saldo_devedor = (total_prestacoes - prestacoes_pagas) * valor_prestacao_atual;

  printf("\nTotal pago pelo consorciado: %.2lf\n", total_pago);
  printf("Saldo devedor: %.2lf\n", saldo_devedor);

  return 0;
}
