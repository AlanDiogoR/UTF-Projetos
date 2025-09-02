#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  float temp;

  printf("\nInforme sua temperatura: ");
  scanf("%f", &temp);

  if (temp >= 37) {
    printf("Você está com febre!");
  } else {
    printf("Você está sem febre!");
  }

  return 0;
}
