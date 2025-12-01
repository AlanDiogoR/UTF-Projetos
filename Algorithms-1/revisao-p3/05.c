/*
fazer um programa em c para cadastro de clientes usando struc  e funcoes. e struc aninhado
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTES 100
#define MAX_NOME 50
#define MAX_ENDERECO 100
#define MAX_TELEFONE 15

struct enderecoProps
{
  char rua[MAX_ENDERECO];
  int numero;
  char cidade[MAX_ENDERECO];
  char estado[MAX_ENDERECO];
  char cep[MAX_ENDERECO];
};

struct clienteProps
{
  char nome[MAX_NOME];
  char telefone[MAX_TELEFONE];
  struct enderecoProps endereco;
};

void cadastrarCliente(struct clienteProps clientes[], int *numClientes)
{
  if (*numClientes >= MAX_CLIENTES)
  {
    printf("Limite de clientes atingido!\n");
    return;
  }

  struct clienteProps novoCliente;

  printf("Digite o nome do cliente: ");
  fgets(novoCliente.nome, MAX_NOME, stdin);
  novoCliente.nome[strcspn(novoCliente.nome, "\n")] = 0;

  printf("Digite o telefone do cliente: ");
  fgets(novoCliente.telefone, MAX_TELEFONE, stdin);
  novoCliente.telefone[strcspn(novoCliente.telefone, "\n")] = 0;

  printf("Digite o endereco do cliente:\n");
  printf("Rua: ");
  fgets(novoCliente.endereco.rua, MAX_ENDERECO, stdin);
  novoCliente.endereco.rua[strcspn(novoCliente.endereco.rua, "\n")] = 0;

  printf("Numero: ");
  scanf("%d", &novoCliente.endereco.numero);
  getchar();

  printf("Cidade: ");
  fgets(novoCliente.endereco.cidade, MAX_ENDERECO, stdin);
  novoCliente.endereco.cidade[strcspn(novoCliente.endereco.cidade, "\n")] = 0;

  printf("Estado: ");
  fgets(novoCliente.endereco.estado, MAX_ENDERECO, stdin);
  novoCliente.endereco.estado[strcspn(novoCliente.endereco.estado, "\n")] = 0;

  printf("CEP: ");
  fgets(novoCliente.endereco.cep, MAX_ENDERECO, stdin);
  novoCliente.endereco.cep[strcspn(novoCliente.endereco.cep, "\n")] = 0;

  clientes[*numClientes] = novoCliente;
  (*numClientes)++;

  printf("Cliente cadastrado com sucesso!\n");
}

void listarClientes(struct clienteProps clientes[], int numClientes)
{
  if (numClientes == 0)
  {
    printf("Nenhum cliente cadastrado!\n");
    return;
  }

  for (int i = 0; i < numClientes; i++)
  {
    printf("Cliente %d:\n", i + 1);
    printf("Nome: %s\n", clientes[i].nome);
    printf("Telefone: %s\n", clientes[i].telefone);
    printf("Endereco:\n");
    printf("  Rua: %s\n", clientes[i].endereco.rua);
    printf("  Numero: %d\n", clientes[i].endereco.numero);
    printf("  Cidade: %s\n", clientes[i].endereco.cidade);
    printf("  Estado: %s\n", clientes[i].endereco.estado);
    printf("  CEP: %s\n", clientes[i].endereco.cep);
    printf("\n");
  }
}

int main()
{
  struct clienteProps clientes[MAX_CLIENTES];
  int numClientes = 0;
  int opcao;

  do
  {
    printf("Menu:\n");
    printf("1. Cadastrar cliente\n");
    printf("2. Listar clientes\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      cadastrarCliente(clientes, &numClientes);
      break;
    case 2:
      listarClientes(clientes, numClientes);
      break;
    case 3:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (opcao != 3);

  return 0;
}
