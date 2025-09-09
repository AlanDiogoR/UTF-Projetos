#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
10. Faça um algoritmo que peça um número inicial e um número final. Em
seguida, deve ser apresentada a contagem do número inicial ao número final. Se o
número inicial for menor que o final, então a contagem será em ordem crescente.
Do contrário, a contagem deverá ser em ordem decrescente. Portanto, se o usuário
digitar primeiro 2, depois 5, deverá ser apresentado: 2, 3, 4 e 5. Mas se o usuário
digitar primeiro 5, depois 2, deverá ser apresentado: 5, 4, 3, 2 e 1.

*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i, n1, n2;

  printf("\n\tContar intervalos na ordem que os valor apresentados");
  printf("\n\t Informe o primeiro número: ");
  scanf("%d", &n1);
  printf("\n\t Informe o segundo número: ");
  scanf("%d", &n2);

  if (n1 > n2) {

    for (i = n1; i >= n2; i--) {
      printf("\n\t %d", i);
    }

  } else if (n1 < n2) {

    for (i = n1; i <= n2; i++) {
      printf("\n\t %d", i);
    }

  } else {
    printf("Valores inválidos");
  }



  return 0;
}
