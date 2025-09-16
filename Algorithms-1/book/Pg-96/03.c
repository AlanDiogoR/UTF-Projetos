#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Faça um algoritmo que conte de 1 a 6, mas no lugar de laço PARA, use
ENQUANTO. Se um outro programador for dar manutenção no seu
algoritmo, qual das duas opções seria mais fácil de dar manutenção, PARA
ou ENQUANTO?
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int i;
  i = 1;

  printf("\n\t Contar até 6 com while!");
  printf("\n\t qual das duas opções seria mais fácil de dar manutenção, PARA ou ENQUANTO?");

  while (i < 7) {
    printf("\n%d", i);
    i++;
  }



  return 0;
}
