#include <stdio.h>

void celsiusParaFarenheit(float celsius, float *farenheit) {
  *farenheit = (9.0 * celsius / 5.0) + 32.0;
}

int main() {
  float celsius, farenheit;

  printf("Digite a temperatura em Celsius: ");
  scanf("%f", &celsius);

  celsiusParaFarenheit(celsius, &farenheit);

  printf("A temperatura em Celsius é: %.2f\n", celsius);
  printf("A temperatura em Farenheit é: %.2f\n", farenheit);

  return 0;
}

