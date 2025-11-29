/*
1. Elabore um programa para armazenar 10 produtos (para isso, crie um vetor de produto de 10 posições). Cada produto deve possuir os campos como o do exercício 1. O programa deve cadastrar os dados dos 10 produtos (um produto por vez). E, no fim, apresentá-los todos. */

#include <stdio.h>
#include <string.h>
#define MAX_PRODUTOS 10
#define MAX_NOME 50

struct produtoProps {
  char nome[MAX_NOME];
  float preco;
  int quantidade;
};


int main() {
  struct produtoProps produtos[MAX_PRODUTOS];

  for (int i = 0; i < MAX_PRODUTOS; i++) {
    printf("Cadastro do produto %d:\n", i + 1);
    printf("Nome: ");
    scanf(" %[^\n]", produtos[i].nome);
    printf("Preco: ");
    scanf("%f", &produtos[i].preco);
    printf("Quantidade: ");
    scanf("%d", &produtos[i].quantidade);
    printf("\n");
  }

  printf("Produtos cadastrados:\n");
  for (int i = 0; i < MAX_PRODUTOS; i++) {
    printf("Produto %d:\n", i + 1);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Preco: %.2f\n", produtos[i].preco);
    printf("Quantidade: %d\n\n", produtos[i].quantidade);
  }

  return 0;
}