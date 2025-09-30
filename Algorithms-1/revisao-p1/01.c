/*
01 - Elabore um programa que recebe a idade de um nadador. O programa deve classificar o
nadador em uma das categorias abaixo:
Infantil A= de 5 a 7 anos, Infantil B= de 8 a 10 anos, Juvenil A= de 11 a 13 anos, Juvenil B= de
14 a 17 anos, Senior= maiores de 18 anos.

*/

#include <stdio.h>

int main()
{
  int idade;

  printf("Digite a idade do nadador: ");
  scanf("%d", &idade);

  if (idade >= 5 && idade <= 7)
  {
    printf("Categoria: Infantil A\n");
  }
  else if (idade >= 8 && idade <= 10)
  {
    printf("Categoria: Infantil B\n");
  }
  else if (idade >= 11 && idade <= 13)
  {
    printf("Categoria: Juvenil A\n");
  }
  else if (idade >= 14 && idade <= 17)
  {
    printf("Categoria: Juvenil B\n");
  }
  else if (idade >= 18)
  {
    printf("Categoria: Senior\n");
  }
  else
  {
    printf("Idade invalida para classificacao.\n");
  }

  return 0;
}
