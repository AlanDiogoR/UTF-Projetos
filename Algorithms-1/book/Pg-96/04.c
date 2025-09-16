#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
. Faça um algoritmo de adivinhação. Primeiro, o algoritmo deve pedir para
o usuário 1 digitar um número. Em seguida, o algoritmo deve pedir para o
usuário 2 digitar um número. O algoritmo deverá continuar pedindo para o
usuário 2 digitar um número enquanto o valor digitado pelo usuário 2 for
diferente do valor digitado pelo usuário 1. Por fim, depois que o usuário 2
acertar o valor digitado, o algoritmo deverá escrever “Parabéns, você
acertou”.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  char usera[15], userb[15];
  int n1, n2;

  printf("\n\t Advinhe o número do primeiro user!");

  printf("\n Informe o nome do user 1: ");
  scanf(" %s", usera);
  printf("\n Informe o nome do user 2: ");
  scanf(" %s", userb);

  printf("%s, informe o número a ser advinhado: ", usera);
  scanf("%d", &n1);

  printf("%s, informe o número para ver se advinhou: ", userb);
  scanf("%d", &n2);

  while (n2 != n1) {
    printf("%s, número errado, tente novamente: ", userb);
    scanf("%d", &n2);
  }

  printf("\n Parabéns %s, você advinhou o número!", userb);


  return 0;
}
