#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int idade;

  printf("\n\t 04");

  printf("\n\nInforme a sua idade: ");
  scanf("%d", &idade);

  if (idade >= 65) {
    printf("\nVocê está na melhor idade");
  } else if (idade >= 40) {
    printf("\nVocê está na meia idade");
  } else if (idade >= 30) {
    printf("\nVocê é adulto");
  } else if (idade >= 18) {
    printf("\nVocê é adulto jovem");
  } else if (idade >= 12) {
    printf("\nVocê é adolescente");
  } else if (idade >= 2) {
    printf("\nVocê é criança");
  } else {
    printf("\nVocê é bebê");
  }

  return 0;
}
