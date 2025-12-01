#include <stdio.h>

void nomePais()
{
  printf("Brasil\n");
}

void nomeEstado()
{
  printf("Paraná\n");
}

void siglaUniversidade()
{
  printf("UTFPR\n");
}

void disciplinaSemestre()
{
  printf("AS61B - 2024/1\n");
}

void valorInvalido()
{
  printf("Valor inválido. Informe uma opção entre 1 e 4.\n");
}

int main()
{
  int opcao;

  printf("Menu:\n");
  printf("1 - Nome do País\n");
  printf("2 - Nome do Estado\n");
  printf("3 - Sigla Universidade\n");
  printf("4 - Disciplina e Semestre\n");
  printf("Escolha uma opção (1-4): ");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    nomePais();
    break;
  case 2:
    nomeEstado();
    break;
  case 3:
    siglaUniversidade();
    break;
  case 4:
    disciplinaSemestre();
    break;
  default:
    valorInvalido();
    break;
  }

  return 0;
}
