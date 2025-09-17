#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Faça um algoritmo que peça para o usuário digitar se é “brasileiro” ou “estrangeiro”.
a. Se for brasileiro, perguntar a região em que nasceu.
   i. Se for “sul”, apresentar a mensagem “você está acostumado com frio”;
   ii. Se for “sudeste”, apresentar a mensagem “você está acostumado com chuva”;
   iii. Se for “centro-oeste”, apresentar a mensagem “você está acostumado com clima abafado”;
   iv. Se for “nordeste”, apresentar a mensagem “você está acostumado com praias bonitas”;
   v. Se for “norte”, apresentar a mensagem “você está acostumado com chuvas no começo da tarde”.
b. Se for estrangeiro, apresentar a mensagem “seja bem-vindo ao Brasil”.
*/

int main()
{
  setlocale(LC_ALL, "Portuguese");

  char nacionalidade[20], regiao[20];

  printf("\nInforme se você é 'brasileiro' ou 'estrangeiro': ");
  scanf("%s", nacionalidade);

  if (strcmp(nacionalidade, "brasileiro") == 0 || strcmp(nacionalidade, "Brasileiro") == 0)
  {
    printf("\nInforme a região em que nasceu (sul, sudeste, centro-oeste, nordeste, norte): ");
    scanf("%s", regiao);

    if (strcmp(regiao, "sul") == 0 || strcmp(regiao, "Sul") == 0)
    {
      printf("\nVocê está acostumado com frio.");
    }
    else if (strcmp(regiao, "sudeste") == 0 || strcmp(regiao, "Sudeste") == 0)
    {
      printf("\nVocê está acostumado com chuva.");
    }
    else if (strcmp(regiao, "centro-oeste") == 0 || strcmp(regiao, "Centro-Oeste") == 0)
    {
      printf("\nVocê está acostumado com clima abafado.");
    }
    else if (strcmp(regiao, "nordeste") == 0 || strcmp(regiao, "Nordeste") == 0)
    {
      printf("\nVocê está acostumado com praias bonitas.");
    }
    else if (strcmp(regiao, "norte") == 0 || strcmp(regiao, "Norte") == 0)
    {
      printf("\nVocê está acostumado com chuvas no começo da tarde.");
    }
    else
    {
      printf("\nRegião não reconhecida.");
    }
  }
  else if (strcmp(nacionalidade, "estrangeiro") == 0 || strcmp(nacionalidade, "Estrangeiro") == 0)
  {
    printf("\nSeja bem-vindo ao Brasil!");
  }
  else
  {
    printf("\nOpção inválida!");
  }

  return 0;
}
