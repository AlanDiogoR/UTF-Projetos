#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
Faça um algoritmo que peça para o usuário digitar um número inferior
a 1 ou superior a 6. Se o valor digitado estiver correto, apresentar a
mensagem “Valor digitado com sucesso”. Do contrário, apresentar a
mensagem “Valor não pode estar entre 1 e 6”
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int n1;

  printf("\n\t Algoritmo que pede para o usuário digitar um número inferiora 1 ou superior a 6");
  printf("\n Informe um número: ");
  scanf("%d", &n1);

  if (n1 < 1 || n1 > 6) {
    printf("\n Valor digitado com sucesso!");
  } else {
    printf("\nValor não pode estar entre 1 e 6");
  }
  

  return 0;
}
