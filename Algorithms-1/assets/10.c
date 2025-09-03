#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int n1;

  printf("\n\t Verificar se é ímpar núeros inteiros!");

  printf("\n Informe um número: ");
  scanf("%d", &n1);

  if ( n1 % 2 ) {
    printf("\n É ímpar!");
  } else {
    printf("\n É par!");
  }

  return 0;
}
