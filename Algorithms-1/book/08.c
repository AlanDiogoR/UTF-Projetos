#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  float salario;

  printf("\n\t 02");

  printf("\n\nInforme o seu salário: ");
  scanf("%f", &salario);

  if (salario > 18000) {
    printf("\nVocê é classe A");
  } else if (salario > 9000) {
    printf("\nVocê é classe B");
  } else {
    printf("\nVocê é classe C ou menor");
  }

  return 0;
}
