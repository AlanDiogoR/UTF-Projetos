#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  float sal;

  printf("Informe seu salário: ");
  scanf("%f", &sal);

  if (sal >= 1045) {
    printf("\nVocê ganha pelo menos um salário minímo!");
  } else {
    printf("\nVocê ganha menos doque um salário minímo!");
  }

  return 0;

}
