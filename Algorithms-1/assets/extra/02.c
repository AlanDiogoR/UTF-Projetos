#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Teorema de Pitágoras: H2
 = L1
2
 + L2
2
. Tem uma infinidade de números com essa combinação. Dado dois números inteiros
positivos, M e N, onde M é maior do que N, desenvolver um algoritmo para entrar com dois números positivos e fornecer os valores, dos
lados e hipotenusa do triângulo gerados combinando M e N. Onde: L1=M
2−N
2
, L2=2∗M ∗N e
Hi p ot e n u s a=M
2N
2
.
*/

int main()
{
  int M, N;
  double L1, L2, Hipotenusa;

  printf("Digite um número inteiro positivo M (M > N): ");
  scanf("%d", &M);
  printf("Digite um número inteiro positivo N (M > N): ");
  scanf("%d", &N);

  if (M <= N || M <= 0 || N <= 0)
  {
    printf("M deve ser maior que N e ambos devem ser positivos.\n");
    return 1;
  }

  L1 = (double)(M * M - N * N);
  L2 = (double)(2 * M * N);
  Hipotenusa = (double)(M * M + N * N);

  printf("Para M = %d e N = %d:\n", M, N);
  printf("Lado 1 (L1) = %.2lf\n", L1);
  printf("Lado 2 (L2) = %.2lf\n", L2);
  printf("Hipotenusa = %.2lf\n", Hipotenusa);

  return 0;
}
