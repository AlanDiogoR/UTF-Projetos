/*
 Elabore um programa para armazenar 10 produtos (para isso, crie um vetor de produto de 10 posições). Cada produto deve possuir os campos como o do exercício 1. O programa deve cadastrar os dados dos 10 produtos (um produto por vez). E, no fim, apresentá-los todos. sem typedef*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUTOS 10
#define MAX_NOME 50

struct ProdutoProps
{
  int codigo;
  char descricao[20];
  char marca[10];
  float preco;
};

int main()
{
  struct ProdutoProps produtos[MAX_PRODUTOS];
  int i;

  for (i = 0; i < MAX_PRODUTOS; i++)
  {
    printf("\n---CADASTRO DE PRODUTO %d---", i + 1);
    printf("\n\tInforme o código: ");
    scanf("%d", &produtos[i].codigo);
    printf("\n\tInforme a descrição: ");
    scanf("%s", produtos[i].descricao);
    printf("\n\tInforme a marca: ");
    scanf("%s", produtos[i].marca);
    printf("\n\tInforme o preco: ");
    scanf("%f", &produtos[i].preco);
    printf("\n---Produto cadastrado---\n");
  }

  printf("\n---LISTA DE PRODUTOS CADASTRADOS---\n");
  for (i = 0; i < MAX_PRODUTOS; i++)
  {
    printf("\nProduto: %d", i + 1);
    printf("\n\t Codigo: %d", produtos[i].codigo);
    printf("\n\t Descricao: %s", produtos[i].descricao);
    printf("\n\t Marca: %s", produtos[i].marca);
    printf("\n\t Preco: %.2f\n", produtos[i].preco);
  }

  return 0;
}
