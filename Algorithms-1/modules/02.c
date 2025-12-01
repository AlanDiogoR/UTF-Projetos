#include <stdio.h>

void identificarPoligono(int lados)
{
  if (lados == 3)
  {
    printf("UM POLÍGONO DE 3 LADOS É UM TRIÂNGULO;\n");
  }
  else if (lados == 4)
  {
    printf("UM POLÍGONO DE 4 LADOS É UM QUADRADO;\n");
  }
  else if (lados == 5)
  {
    printf("UM POLÍGONO DE 5 LADOS É UM PENTÁGONO.\n");
  }
  else
  {
    printf("Número de lados inválido. Informe um valor entre 3 e 5.\n");
  }
}

int main()
{
  int lados;

  printf("Digite o número de lados do polígono (3, 4 ou 5): ");
  scanf("%d", &lados);

  identificarPoligono(lados);

  return 0;
}
