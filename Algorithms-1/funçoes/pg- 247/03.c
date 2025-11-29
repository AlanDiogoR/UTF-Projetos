/*
Crie um algoritmo que peça uma temperatura em Farenheit, faça a
conversão para Celsius e apresente o valor convertido. C= 5*(F-32)/9
*/

#include <stdio.h>

void farenheitParaCelsius(float farenheit, float *celsius) {// * é para indicar que é um ponteiro (testeando como funciona ponteiro)
  *celsius = 5.0 * (farenheit - 32.0) / 9.0;
}

int main() {
  float farenheit, celsius;

  printf("Digite a temperatura em Farenheit: ");
  scanf("%f", &farenheit);

  farenheitParaCelsius(farenheit, &celsius);

  printf("A temperatura em Celsius é: %.2f\n", celsius);

  return 0;
}

