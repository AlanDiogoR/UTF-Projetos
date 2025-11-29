/*
Crie um algoritmo que peça uma temperatura em Farenheit, faça a
conversão para Celsius e apresente o valor em Farenheit e em
Celsius. C= 5*(F-32)/9

*/

#include <stdio.h>

void farenheitParaCelsius(float farenheit, float *celsius) {
  *celsius = 5.0 * (farenheit - 32.0) / 9.0;
}

int main() {
  float farenheit, celsius;

  printf("Digite a temperatura em Farenheit: ");
  scanf("%f", &farenheit);

  farenheitParaCelsius(farenheit, &celsius);

  printf("A temperatura em Farenheit é: %.2f\n", farenheit);
  printf("A temperatura em Celsius é: %.2f\n", celsius);

  return 0;
}

