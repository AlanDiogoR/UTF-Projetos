#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  int numeroPessoas, i, idade;
  char nome[50], doente[10];

  printf("\n\t Apresentar avisar se doador!");

  printf("\n\t Informe o número de candidatos: ");
  scanf("%d", &numeroPessoas);
  getchar();

  for (i = 0; i < numeroPessoas; i++) {

    printf("\n\t Informe seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("\n\t Tem alguma doença? (sim ou nao): ");
    fgets(doente, sizeof(doente), stdin);
    doente[strcspn(doente, "\n")] = '\0';

    printf("\n\t Informe sua idade: ");
    scanf("%d", &idade);
    getchar();

    if (idade >= 18 && strcmp(doente, "nao") == 0) {
      printf("\n\t Olá, %s! Você atende os requisitos de um doador!\n", nome);
    } else {
      printf("\n\t Olá, %s! Você não atende os requisitos de um doador!\n", nome);
    }
  }
  return 0;
}
