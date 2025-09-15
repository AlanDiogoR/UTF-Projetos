#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double angulo_graus, angulo_radianos;
  double seno, cosseno, tangente;

  printf("Digite um ângulo em graus: ");
  scanf("%lf", &angulo_graus);

  angulo_radianos = angulo_graus * (M_PI / 180.0);

  seno = sin(angulo_radianos);
  cosseno = cos(angulo_radianos);
  tangente = tan(angulo_radianos);

  printf("\nPara o ângulo de %.2lf graus:\n", angulo_graus);
  printf("Seno: %.4lf\n", seno);
  printf("Cosseno: %.4lf\n", cosseno);
  printf("Tangente: %.4lf\n", tangente);

  return 0;
}
