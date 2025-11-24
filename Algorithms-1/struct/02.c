#include <stdio.h>

struct userProps
{
  int iden;
  char name[10];
  char cidade[15];
  int ndependentes;
};

int main()
{
  struct userProps user;

  do
  {
    printf("\n\tInforme a identificação (0 a 100): ");
    scanf("%d", &user.iden);
  } while (user.iden < 0 || user.iden > 100);

  printf("\n\tInforme o nome: ");
  scanf("%9s", user.name);

  printf("\n\tInforme a cidade: ");
  scanf("%14s", user.cidade);

  printf("\n\tInforme o número de dependentes: ");
  scanf("%d", &user.ndependentes);

  printf("\n\n--- DADOS DO CLIENTE ---");
  printf("\n\tIdentificação: %d", user.iden);
  printf("\n\tNome: %s", user.name);
  printf("\n\tCidade: %s", user.cidade);
  printf("\n\tDependentes: %d\n", user.ndependentes);

  return 0;
}
