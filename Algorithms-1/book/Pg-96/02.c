#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Faça um algoritmo que peça para o usuário digitar um número inteiro
entre 1 e 6. Após ser digitado, enquanto esse número for menor que 1 ou
maior que 6, escreva a mensagem “valor inválido. Tente novamente”. E o
algoritmo deverá esperar por um novo número. Neste exemplo, se o usuário
digitar um número dentro do intervalo correto de primeira, então o
algoritmo não precisará escrever a mensagem de valor inválido.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int n1;

  printf("\n\t Verificar se está entre 1 e 6!");

  printf("\n Informe um número: ");
  scanf("%d", &n1);

  do {
    printf("\n Valor inválido!");
    printf("\n Informe outro número: ");
    scanf("%d", &n1);
  } while (n1 < 1 || n1 > 6);


  return 0;
}
