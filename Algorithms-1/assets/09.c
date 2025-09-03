#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int totalParafusos, parafusosDefeito;
  float limite;

  printf("\nInforme o número de parafusos: ");
  scanf("%d", &totalParafusos);
  printf("\nInforme o número de parafusos com defeitos: ");
  scanf("%d", &parafusosDefeito);

  limite = totalParafusos * 0.10;

  if (parafusosDefeito >  limite) {
    printf("\nO limite de peças com defeitos é: %.2f", limite);
    printf("\nEstamos com uma produção ruim!");
  } else {
    printf("\nO limite de peças com defeitos é: %.2f", limite);
    printf("\nEstamos com uma produção boa!");
  }


  return 0;
}
