#include <stdio.h>
#define TAM 3

struct clienteProps
{
  int cod;
  char name[20];
  int age;
  float sal;
};

int main()
{
  struct clienteProps cliente[TAM];
  int i;

  for (i = 0; i < TAM; i++)
  {
    printf("\n\tInforme o código do cliente: ");
    scanf("%d", &cliente[i].cod);

    printf("\n\tInforme o nome do cliente: ");
    scanf("%s", cliente[i].name);

    printf("\n\tInforme a idade do cliente: ");
    scanf("%d", &cliente[i].age);

    printf("\n\tInforme o salario do cliente: ");
    scanf("%f", &cliente[i].sal);
  }

  for (i = 0; i < TAM; i++)
  {
    printf("\n---Cliente---");
    printf("\n|codigo| |%d|", cliente[i].cod);
    printf("\n|Nome| |%s|", cliente[i].name);
    printf("\n|Idade| |%d|", cliente[i].age);
    printf("\n|salario| |%f|", cliente[i].sal);
    printf("\n-------------");
  }

  return 0;
}
