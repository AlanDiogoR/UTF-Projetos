#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int n1, n2;

  printf("\n Abaixo apenas número inteiros e sem repetir!");
  printf("\n Informe o primeiro número: ");
  scanf("%d", &n1);
  printf("\n Informe o segundo número: ");
  scanf("%d", &n2);

  if ( n1 > n2 ) {
    printf("\n O menor número é : %c", n2);
  }
  

  return 0;
}
