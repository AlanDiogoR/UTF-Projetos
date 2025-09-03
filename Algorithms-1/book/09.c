#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  float temperatura;

  printf("\n\t 03");

  printf("\n\nInforme a temperatura da água (ºC): ");
  scanf("%f", &temperatura);

  if (temperatura > 100) {
    printf("\nA água está em estado de vapor");
  } else if (temperatura > 0) {
    printf("\nA água está em estado líquido");
  } else {
    printf("\nA água está em estado sólido");
  }

  return 0;
}
