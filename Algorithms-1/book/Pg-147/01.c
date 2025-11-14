#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int opcao, i, j;
  char continuar;

  srand(time(NULL)); // Inicializa o gerador de números aleatórios

  do
  {
    printf("\n================ MENU DE EXERCICIOS ================\n");
    printf("1 - Matriz 2x2 (inteiros)\n");
    printf("2 - Matriz 3x3 (reais)\n");
    printf("3 - Matriz 3x2 (inteiros, inversa)\n");
    printf("4 - Matriz 2x3 (inteiros, soma de linhas)\n");
    printf("5 - Multiplicacao de matrizes 3x3\n");
    printf("Escolha uma opcao (1 a 5): ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
      // -------------------- EXERCÍCIO 1 --------------------
      int mat[2][2];

      printf("\nPreenchendo matriz 2x2:\n");
      for (i = 0; i < 2; i++)
      {
        for (j = 0; j < 2; j++)
        {
          printf("Digite mat[%d][%d]: ", i, j);
          scanf("%d", &mat[i][j]);
        }
      }

      printf("\nMatriz 2x2:\n");
      for (i = 0; i < 2; i++)
      {
        for (j = 0; j < 2; j++)
        {
          printf("%d ", mat[i][j]);
        }
        printf("\n");
      }
      break;
    }

    case 2:
    {
      // -------------------- EXERCÍCIO 2 --------------------
      float mat[3][3];

      printf("\nPreenchendo matriz 3x3 com reais:\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 3; j++)
        {
          printf("Digite mat[%d][%d]: ", i, j);
          scanf("%f", &mat[i][j]);
        }
      }

      printf("\nMatriz 3x3:\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 3; j++)
        {
          printf("%.2f ", mat[i][j]);
        }
        printf("\n");
      }
      break;
    }

    case 3:
    {
      // -------------------- EXERCÍCIO 3 --------------------
      int mat[3][2];

      printf("\nPreenchendo matriz 3x2:\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 2; j++)
        {
          printf("Digite mat[%d][%d]: ", i, j);
          scanf("%d", &mat[i][j]);
        }
      }

      printf("\nMatriz original 3x2:\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 2; j++)
        {
          printf("%d ", mat[i][j]);
        }
        printf("\n");
      }

      printf("\nMatriz invertida (de trás pra frente):\n");
      for (i = 2; i >= 0; i--)
      {
        for (j = 1; j >= 0; j--)
        {
          printf("%d ", mat[i][j]);
        }
        printf("\n");
      }
      break;
    }

    case 4:
    {
      // -------------------- EXERCÍCIO 4 --------------------
      int mat[2][3], somaLinha;

      printf("\nPreenchendo matriz 2x3:\n");
      for (i = 0; i < 2; i++)
      {
        for (j = 0; j < 3; j++)
        {
          printf("Digite mat[%d][%d]: ", i, j);
          scanf("%d", &mat[i][j]);
        }
      }

      printf("\nSoma das linhas:\n");
      for (i = 0; i < 2; i++)
      {
        somaLinha = 0;
        for (j = 0; j < 3; j++)
        {
          somaLinha += mat[i][j];
        }
        printf("Soma da linha %d = %d\n", i + 1, somaLinha);
      }
      break;
    }

    case 5:
    {
      // -------------------- EXERCÍCIO 5 --------------------
      int mat1[3][3], mat2[3][3], mult[3][3];

      printf("\nPreencha a primeira matriz 3x3:\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 3; j++)
        {
          printf("mat1[%d][%d]: ", i, j);
          scanf("%d", &mat1[i][j]);
        }
      }

      printf("\nPreencha a segunda matriz 3x3:\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 3; j++)
        {
          printf("mat2[%d][%d]: ", i, j);
          scanf("%d", &mat2[i][j]);
        }
      }

      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 3; j++)
        {
          mult[i][j] = mat1[i][j] * mat2[i][j];
        }
      }

      printf("\nMatriz resultante (multiplicacao posicional):\n");
      for (i = 0; i < 3; i++)
      {
        for (j = 0; j < 3; j++)
        {
          printf("%d ", mult[i][j]);
        }
        printf("\n");
      }
      break;
    }

    default:
      printf("\nOpcao invalida!\n");
    }

    printf("\nDeseja continuar (S/N)? ");
    scanf(" %c", &continuar);

  } while (continuar == 'S' || continuar == 's');

  printf("\nPrograma finalizado!\n");
  return 0;
}
