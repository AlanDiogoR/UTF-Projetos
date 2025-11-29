#include <stdio.h>

float celsiusParaFarenheit(float celsius) {
  return (9.0 * celsius / 5.0) + 32.0;
}

int main() {
  float celsius, farenheit;

  printf("Digite a temperatura em Celsius: ");
  scanf("%f", &celsius);

  farenheit = celsiusParaFarenheit(celsius);

  printf("A temperatura em Farenheit é: %.2f\n", farenheit);

  return 0;
}