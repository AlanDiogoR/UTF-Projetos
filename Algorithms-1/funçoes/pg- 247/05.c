/*com funbcoes e esteticamente boniyto dentro de umquadrado as perguntas e a resposta Crie um algoritmo que peça duas notas, calcule a média e apresente
a média 
*/

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
  printf("+----------------------------+\n");

  return 0;
}