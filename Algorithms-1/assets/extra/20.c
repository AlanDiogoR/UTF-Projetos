#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double raio;
  double comprimento, area, volume;

  printf("Digite o raio da esfera: ");
  scanf("%lf", &raio);

  comprimento = 2 * M_PI * raio; // Comprimento da circunferência máxima
  area = M_PI * pow(raio, 2);    // Área do círculo máximo (não da superfície da esfera)
  volume = (4.0 / 3.0) * PI * pow(raio, 3);

  printf("\nPara uma esfera com raio %.2lf:\n", raio);
  printf("Comprimento da circunferência máxima: %.2lf\n", comprimento);
  printf("Área do círculo máximo: %.2lf\n", area);
  printf("Volume da esfera: %.2lf\n", volume);

  return 0;
}
