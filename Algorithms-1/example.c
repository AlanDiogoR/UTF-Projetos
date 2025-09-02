#include<stdio.h>
#include<locale.h>

int main() {
  float p1, p2, media;
  setlocale(LC_ALL, "Portuguese");

  printf("\n Informe a primeira nota: ");
  scanf("%f", &p1);
  printf("\n Informe a segunda nota: ");
  scanf("%f", &p2);

  media =  (p1 + p2) / 2;

  if (media >= 6) {
    printf("\n Aprovado com média: %.2f", media);
  } else {
    printf("\n Reprovado com média: %.2f", media);
  }

  return 0;
}

