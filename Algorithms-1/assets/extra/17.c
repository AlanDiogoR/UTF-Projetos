#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double nota1, nota2, nota3, nota4, media_ponderada;

  printf("Digite a nota da 1ª avaliação: ");
  scanf("%lf", &nota1);
  printf("Digite a nota da 2ª avaliação: ");
  scanf("%lf", &nota2);
  printf("Digite a nota da 3ª avaliação: ");
  scanf("%lf", &nota3);
  printf("Digite a nota da 4ª avaliação: ");
  scanf("%lf", &nota4);

  media_ponderada = (nota1 * 2 + nota2 * 4 + nota3 * 6 + nota4 * 8) / (2 + 4 + 6 + 8);

  printf("A média ponderada final do aluno é: %.2lf\n", media_ponderada);

  return 0;
}
