/*
2.Elabore um programa para armazenar 10 produtos (para isso, crie um vetor de produto de 10 posições). Cada produto deve possuir os campos como o do exercício 1. O programa deve pedir os dados dos 10 produtos (um produto por vez). Em seguida, o programa deve apresentar o seguinte menu: “1- Alterar dados do produto; 2-Ver dados do produto; 0 - sair”. Uma vez que o usuário escolha entre 1 ou 2, o programa deve pedir qual produto (entre 0 e 9) o usuário deseja alterar/ver. Se o usuário digitar 1, o programa deverá pedir para ele digitar os novos valores/dados do produto e retornar ao menu inicial. Se o usuário digitar 2, o programa deverá apresentar os dados do produto e voltar ao menu inicial. Isto deve se repetir até que o usuário digite 0.
*/

#include <stdio.h>
#include <string.h>
#define maxProdutos 10
#define maxNome 50
#define maxMarca 30
#define maxCategoria 20
#define maxFornecedor 40
#define maxDescricao 100
#define maxCodigo 15
#define maxData 11

struct produtoProps {
  char nome[maxNome];
  char marca[maxMarca];
  char categoria[maxCategoria];
  char fornecedor[maxFornecedor];
  char descricao[maxDescricao];
  char codigo[maxCodigo];
  char dataFabricacao[maxData];
  char dataValidade[maxData];
  float preco;
  int quantidade;
};

void lerProduto(struct produtoProps *produto) {
  printf("Nome: ");
  fgets(produto->nome, maxNome, stdin);
  printf("Marca: ");
  fgets(produto->marca, maxMarca, stdin);
  printf("Categoria: ");
  fgets(produto->categoria, maxCategoria, stdin);
  printf("Fornecedor: ");
  fgets(produto->fornecedor, maxFornecedor, stdin);
  printf("Descricao: ");
  fgets(produto->descricao, maxDescricao, stdin);
  printf("Codigo: ");
  fgets(produto->codigo, maxCodigo, stdin);
  printf("Data de Fabricacao (DD/MM/AAAA): ");
  fgets(produto->dataFabricacao, maxData, stdin);
  printf("Data de Validade (DD/MM/AAAA): ");
  fgets(produto->dataValidade, maxData, stdin);
  printf("Preco: ");
  scanf("%f", &produto->preco);
  printf("Quantidade: ");
  scanf("%d", &produto->quantidade);
  getchar(); 
}

void mostrarProduto(struct produtoProps produto) {
  printf("Nome: %s", produto.nome);
  printf("Marca: %s", produto.marca);
  printf("Categoria: %s", produto.categoria);
  printf("Fornecedor: %s", produto.fornecedor);
  printf("Descricao: %s", produto.descricao);
  printf("Codigo: %s", produto.codigo);
  printf("Data de Fabricacao: %s", produto.dataFabricacao);
  printf("Data de Validade: %s", produto.dataValidade);
  printf("Preco: %.2f\n", produto.preco);
  printf("Quantidade: %d\n", produto.quantidade);
}

int main() {
  struct produtoProps produtos[maxProdutos];
  int i, opcao, indice;

  for (i = 0; i < maxProdutos; i++) {
    printf("Digite os dados do produto %d:\n", i + 1);
    lerProduto(&produtos[i]);
  }

  do {
    printf("\nMenu:\n1- Alterar dados do produto\n2- Ver dados do produto\n0- Sair\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); 

    if (opcao == 1 || opcao == 2) {
      printf("Digite o indice do produto (0 a 9): ");
      scanf("%d", &indice);
      getchar(); 

      if (indice < 0 || indice >= maxProdutos) {
        printf("Indice invalido!\n");
        continue;
      }

      if (opcao == 1) {
        printf("Digite os novos dados do produto %d:\n", indice + 1);
        lerProduto(&produtos[indice]);
      } else if (opcao == 2) {
        printf("Dados do produto %d:\n", indice + 1);
        mostrarProduto(produtos[indice]);
      }
    }
  } while (opcao != 0);

  return 0;
}

