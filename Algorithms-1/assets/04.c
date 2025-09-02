#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int senha;

  printf("\nInforme a senha (apenas numérica-6d): ");
  scanf("%d", &senha);

  if (senha != 123456) {
    printf("\nSenha não confere!");
  }


  return 0;
}
