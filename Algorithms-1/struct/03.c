/*

3. Elabore um programa que tenha um registro (estrutura) que represente N cheques.
O usuário deve digitar o NUMERO, VALOR, CIDADE. O valor do cheque não pode ser 0.
 Apresentar quantidade de cheques cadastrados. Não utilizar vetor.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CIDADE 50
#define MAX_CHEQUES 100
#define MAX_NUMERO 20

typedef struct
{
  char numero[MAX_NUMERO];
  float valor;
  char cidade[MAX_CIDADE];
} chequeProps;

int main()
{
  chequeProps *cheques[MAX_CHEQUES];
  int count = 0;
  char opcao;

  do
  {
    if (count >= MAX_CHEQUES)
    {
      printf("Limite de cheques atingido.\n");
      break;
    }

    chequeProps *novoCheque = (chequeProps *)malloc(sizeof(chequeProps));
    if (novoCheque == NULL)
    {
      printf("Erro ao alocar memoria.\n");
      break;
    }

    printf("Digite o numero do cheque: ");
    scanf("%s", novoCheque->numero);

    do
    {
      printf("Digite o valor do cheque (nao pode ser 0): ");
      scanf("%f", &novoCheque->valor);
      if (novoCheque->valor == 0)
      {
        printf("Valor invalido. Tente novamente.\n");
      }
    } while (novoCheque->valor == 0);

    printf("Digite a cidade do cheque: ");
    scanf("%s", novoCheque->cidade);

    cheques[count] = novoCheque;
    count++;

    printf("Deseja cadastrar outro cheque? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  printf("Quantidade de cheques cadastrados: %d\n", count);

  for (int i = 0; i < count; i++)
  {
    free(cheques[i]);
  }

  return 0;
}
