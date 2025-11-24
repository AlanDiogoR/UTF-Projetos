#include <stdio.h>

struct productProps
{
  int codigo;
  char descricao[20];
  char marca[10];
  float preco;
};

int main()
{
  struct productProps product;

  printf("\n---CAFASTRO DE PRODUTOS---");
  printf("\n\tInforme o código: ");
  scanf("%d", &product.codigo);
  printf("\n\tInforme a descrição: ");
  scanf("%s", product.descricao);
  printf("\n\tInforme a marca: ");
  scanf("%s", product.marca);
  printf("\n\tInforme o preco: ");
  scanf("%f", &product.preco);
  printf("\n---Produto cadastrado---");

  printf("\nProduto: 01");
  printf("\n\t Codigo: %d", product.codigo);
  printf("\n\t Descricao: %s", product.descricao);
  printf("\n\t Marca: %s", product.marca);
  printf("\n\t Preco: %f", product.preco);

  return 0;
}
