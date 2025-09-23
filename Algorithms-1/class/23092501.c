#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
for, exemplo professora - alunos
*/

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int i, idade, soma;
  soma = 0;

  printf("\n\t Valor discreto! teste");

  for (i = 1; i < 6; i++)
  {
    printf("\n\t Informe a idade do %d° aluno: ", i);
    scanf("%i", &idade);

    soma = soma + idade;
  }

  printf("A soma das idades dos alunos da ESA é: %i", soma);

  return 0;
}
