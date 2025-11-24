#include <stdio.h>

struct dataProps
{
  int dia;
  int mes;
  int ano;
};

struct horaProps
{
  int hora;
  int minutos;
  int segundos;
};

struct pessoaProps
{
  int codigo;
  char name[10];
  struct dataProps aniversario;
  struct horaProps hora;
};

#define tam 3

int main()
{
  struct pessoaProps pessoa[tam];
  int i;

  for (i = 0; i < tam; i++)
  {
    printf("\n\t Informe o código: ");
    scanf("%d", &pessoa[i].codigo);
    printf("\n\t Informe o nome: ");
    scanf("%s", pessoa[i].name);
    printf("\n\t Informe o aniversario aa/mm/aa: ");
    scanf("%d", &pessoa[i].aniversario.dia);
    scanf("%d", &pessoa[i].aniversario.mes);
    scanf("%d", &pessoa[i].aniversario.ano);
    printf("\n\t Informe a hora: ");
    scanf("%d", &pessoa[i].hora.hora);
    scanf("%d", &pessoa[i].hora.minutos);
    scanf("%d", &pessoa[i].hora.segundos);
  }

  for (i = 0; i < tam; i++)
  {
    printf("\n-----USER %d-----", i + 1);
    printf("\n\t Código: %d", pessoa[i].codigo);
    printf("\n\t Nome: %s", pessoa[i].name);
    printf("\n\t Aniversario: /%d/%d/%d", pessoa[i].aniversario.ano, pessoa[i].aniversario.dia, pessoa[i].aniversario.mes);
    printf("\n\t Hora: %d:%d:%d", pessoa[i].hora.hora, pessoa[i].hora.minutos, pessoa[i].hora.segundos);
    printf("\n---------------------");
  }

  return 0;
}
