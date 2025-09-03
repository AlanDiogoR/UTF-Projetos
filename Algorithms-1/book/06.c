#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  printf("\n\t Verificador de triangulos, apenas números inteiros!");

  int n1, n2, n3;

  printf("\n Informe o primeiro lado inteiro: ");
  scanf("%d", &n1);
  printf("\n Informe o segundo lado inteiro: ");
  scanf("%d", &n2);
  printf("\n Informe o terceiro lado inteiro: ");
  scanf("%d", &n3);

  if ( n3 < (n1 + n2) && n2 < (n3 + n1) && n1 < (n3 + n2)  ) {
    printf("\n É um triângulo!");
  } else {
    printf("Não forma um triângulo!");
  }

  return 0;
}
