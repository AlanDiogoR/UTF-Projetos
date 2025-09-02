#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int senha, rsenha;

  printf("Senha numérica!");
  printf("\nCrie a senha: ");
  scanf("%d",senha);
  printf("\nConfirme a senha: ");
  scanf("%d",rsenha);

  if (senha == rsenha) {
    printf("Senha criada com sucesso");
  } else {
    printf("Senha não confere");
  }


  return 0;
}
