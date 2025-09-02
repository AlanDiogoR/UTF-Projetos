#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  float salario;

  printf("\n Informe seu salário: R$");
  scanf("%f", &salario);

  if (salario >= 10000) {
    printf("\nVocê recebe um bom salário");
  } else {
    printf("\nvocê não ganha muito!");
  }

  return 0;
}
