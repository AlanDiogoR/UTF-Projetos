#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double raio, altura, area, volume;

  printf("Digite o raio do cilindro: ");
  scanf("%lf", &raio);
  printf("Digite a altura do cilindro: ");
  scanf("%lf", &altura);

  area = 2 * M_PI * raio * (altura + raio);
  volume = M_PI * pow(raio, 2) * altura;

  printf("A área do cilindro é: %.2lf\n", area);
  printf("O volume do cilindro é: %.2lf\n", volume);

  return 0;
}
