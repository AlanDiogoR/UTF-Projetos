#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
Faça um algoritmo que peça para o usuário digitar um número entre 1
e 6 (inclusive). Se o valor digitado estiver no intervalo, apresentar a
mensagem “Valor digitado com sucesso”. Do contrário, apresentar a
mensagem “Valor fora do intervalo permitido”.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int n1;

  printf("\n\t Verificar se o número inteiro está dentro de um intervalo!");
  printf("\n Informe um número: ");
  scanf("%c", &n1);

  if (n1 >= 1 || n1 <= 6) {
    printf("\n Valor dentro do intervalo!");
  } else {
    printf("\n Valor fora do intervalo!");
  }
  

  return 0;
}
