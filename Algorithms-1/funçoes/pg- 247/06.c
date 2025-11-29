/*esteticamente bonito como se fosse uma tela de pc normal em  um quadfrado ->  . Crie um algoritmo que peça duas notas, calcule a média e informe
se o aluno está aprovado (se sua nota for maior ou igual a 6) ou se
está de recuperação (se sua nota for menor que 6).*/

#include <stdio.h>

void calcularMedia(float nota1, float nota2, float *media) {
  *media = (nota1 + nota2) / 2.0;
}

int main() {
  float nota1, nota2, media;

  printf("+----------------------------+\n");
  printf("|      Calculadora de Média   |\n");
  printf("+----------------------------+\n");

  printf("Digite a primeira nota: ");
  scanf("%f", &nota1);

  printf("Digite a segunda nota: ");
  scanf("%f", &nota2);

  calcularMedia(nota1, nota2, &media);

  printf("+----------------------------+\n");
  printf("|        Resultado           |\n");
  printf("+----------------------------+\n");
  printf("A média das notas é: %.2f\n", media);

  if (media >= 6.0) {
    printf("Status: Aprovado\n");
  } else {
    printf("Status: Recuperação\n");
  }

  printf("+----------------------------+\n");

  return 0;
}