#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int totalParafusos, parafusosDefeito;

  printf("\nInforme o número de parafusos: ");
  scanf("%c", &totalParafusos);

  return 0;
}
