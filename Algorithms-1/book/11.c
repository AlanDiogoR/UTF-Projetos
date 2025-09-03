#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  float altura, massa, imc;

  printf("\n\t 05");

  printf("\n\nInforme sua altura (em metros): ");
  scanf("%f", &altura);
  printf("\nInforme sua massa (em kg): ");
  scanf("%f", &massa);

  imc = massa / (altura * altura);
  printf("\nSeu IMC é: %.2f", imc);

  if (imc < 17) {
    printf("\nMuito abaixo do peso");
  } else if (imc < 18.5) {
    printf("\nAbaixo do peso");
  } else if (imc < 25) {
    printf("\nPeso normal");
  } else if (imc < 30) {
    printf("\nAcima do peso");
  } else if (imc < 35) {
    printf("\nObesidade I");
  } else if (imc < 40) {
    printf("\nObesidade II (severa)");
  } else {
    printf("\nObesidade III (mórbida)");
  }

  return 0;
}
