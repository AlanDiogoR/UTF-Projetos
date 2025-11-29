#include <stdio.h>

void receberNumero(int *numero) {
  printf("Digite um número inteiro: ");
  scanf("%d", numero);
}

void verificarParImpar(int numero, char *resultado) {
  if (numero % 2 == 0) {
    *resultado = 'P'; 
  } else {
    *resultado = 'I'; 
}

void apresentarResultado(int numero, char resultado) {
  if (resultado == 'P') {
    printf("O número %d é Par.\n", numero);
  } else {
    printf("O número %d é Ímpar.\n", numero);
  }
}

int main() {
  int numero;
  char resultado;

  receberNumero(&numero);
  verificarParImpar(numero, &resultado);
  apresentarResultado(numero, resultado);

  return 0;
}
