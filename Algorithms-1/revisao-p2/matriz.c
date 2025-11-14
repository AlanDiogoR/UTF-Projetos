#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM10 10
#define LIN4 4
#define COL4 4
#define LIN3 3
#define COL3 3
#define FILAS 15
#define CADEIRAS 100
#define PRECO 10.0

int main()
{
  int opcao;
  char continuar;
  srand(time(NULL)); // inicializa gerador de números aleatórios

  do
  {
    printf("\n=============== MENU ===============\n");
    printf("1 - REV_EX03 - Dois vetores aleatorios e matriz 10x2 + vetor soma\n");
    printf("2 - REV_EX04 - Matriz 4x4 e operacoes (maiores que 10, diagonal, identidade)\n");
    printf("3 - REV_EX05 - Matriz 3x3 (menor valor, soma das linhas)\n");
    printf("4 - REV_EX06 - Venda de ingressos (matriz 15x100)\n");
    printf("====================================\n");
    printf("Escolha uma opcao (1 a 4): ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    // -----------------------------------------------------------------
    case 1:
    { // REV_EX03
      int v1[TAM10], v2[TAM10], soma[TAM10];
      int matriz[TAM10][2];

      for (int i = 0; i < TAM10; i++)
      {
        v1[i] = rand() % 100;
        v2[i] = rand() % 100;
        soma[i] = v1[i] + v2[i];
        matriz[i][0] = v1[i];
        matriz[i][1] = v2[i];
      }

      printf("\nMatriz 10x2 (dois vetores aleatorios):\n");
      for (int i = 0; i < TAM10; i++)
      {
        printf("[%2d]  %3d   %3d\n", i, matriz[i][0], matriz[i][1]);
      }

      printf("\nVetor soma:\n");
      for (int i = 0; i < TAM10; i++)
      {
        printf("%d ", soma[i]);
      }
      printf("\n");
      break;
    }

    // -----------------------------------------------------------------
    case 2:
    { // REV_EX04
      int m[LIN4][COL4];
      int maiores10 = 0, somaDiagonal = 0;

      // a) preencher matriz com valores aleatórios
      for (int i = 0; i < LIN4; i++)
      {
        for (int j = 0; j < COL4; j++)
        {
          m[i][j] = rand() % 21; // 0 a 20
          if (m[i][j] > 10)
            maiores10++;
          if (i == j)
            somaDiagonal += m[i][j];
        }
      }

      printf("\nMatriz gerada:\n");
      for (int i = 0; i < LIN4; i++)
      {
        for (int j = 0; j < COL4; j++)
        {
          printf("%3d ", m[i][j]);
        }
        printf("\n");
      }

      printf("\nQuantidade de valores > 10: %d\n", maiores10);
      printf("Soma da diagonal principal: %d\n", somaDiagonal);

      // c) transformar em matriz identidade
      for (int i = 0; i < LIN4; i++)
      {
        for (int j = 0; j < COL4; j++)
        {
          if (i == j)
            m[i][j] = 1;
          else
            m[i][j] = 0;
        }
      }

      printf("\nMatriz identidade resultante:\n");
      for (int i = 0; i < LIN4; i++)
      {
        for (int j = 0; j < COL4; j++)
        {
          printf("%2d ", m[i][j]);
        }
        printf("\n");
      }
      break;
    }

    // -----------------------------------------------------------------
    case 3:
    { // REV_EX05
      int m[LIN3][COL3];
      int menor, linhaMenor = 0, colunaMenor = 0;
      int somaLinha;

      printf("\nDigite valores inteiros positivos para matriz 3x3:\n");
      for (int i = 0; i < LIN3; i++)
      {
        for (int j = 0; j < COL3; j++)
        {
          scanf("%d", &m[i][j]);
        }
      }

      menor = m[0][0];
      for (int i = 0; i < LIN3; i++)
      {
        for (int j = 0; j < COL3; j++)
        {
          if (m[i][j] < menor)
          {
            menor = m[i][j];
            linhaMenor = i;
            colunaMenor = j;
          }
        }
      }

      printf("\nMatriz original:\n");
      for (int i = 0; i < LIN3; i++)
      {
        for (int j = 0; j < COL3; j++)
        {
          printf("%3d ", m[i][j]);
        }
        printf("\n");
      }

      printf("\nMenor valor: %d (linha %d, coluna %d)\n", menor, linhaMenor, colunaMenor);

      printf("\nSoma dos valores de cada linha:\n");
      for (int i = 0; i < LIN3; i++)
      {
        somaLinha = 0;
        for (int j = 0; j < COL3; j++)
        {
          somaLinha += m[i][j];
        }
        printf("Linha %d: %d\n", i, somaLinha);
      }
      break;
    }

    // -----------------------------------------------------------------
    case 4:
    { // REV_EX06
      int estadio[FILAS][CADEIRAS];
      int vazias = 0, inteiras = 0, meias = 0;
      double total = 0.0;

      // Preencher com valores aleatórios: 0, 1, 2
      for (int i = 0; i < FILAS; i++)
      {
        for (int j = 0; j < CADEIRAS; j++)
        {
          estadio[i][j] = rand() % 3;
          if (estadio[i][j] == 0)
            vazias++;
          else if (estadio[i][j] == 1)
            inteiras++;
          else
            meias++;
        }
      }

      total = (inteiras * PRECO) + (meias * (PRECO / 2.0));

      printf("\n=== RELATORIO DO JOGO ===\n");
      printf("Cadeiras vazias: %d\n", vazias);
      printf("Pagantes inteiras: %d\n", inteiras);
      printf("Pagantes meias: %d\n", meias);
      printf("Total arrecadado: R$ %.2f\n", total);

      printf("\nExemplo da ocupacao (primeiras 5 filas):\n");
      for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 20; j++)
        {
          printf("%d ", estadio[i][j]);
        }
        printf("\n");
      }
      break;
    }

    default:
      printf("\nOpcao invalida!\n");
    }

    printf("\nDeseja continuar? (s/n): ");
    scanf(" %c", &continuar);

  } while (continuar == 's' || continuar == 'S');

  printf("\nPrograma encerrado.\n");
  return 0;
}
