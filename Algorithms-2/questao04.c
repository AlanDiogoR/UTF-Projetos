/*
 * Nome completo: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 *
 * Enunciado da questao:
 * Escreva um programa que calcule a soma de duas matrizes MxN de numeros do tipo float.
 *
 * O programa deve:
 * a) alocar dinamicamente as matrizes necessarias para a realizacao da soma, a partir
 *    dos valores de linha e coluna fornecidos pelo usuario
 * b) preencher randomicamente as duas matrizes que serao somadas
 * c) realizar a soma das duas matrizes, armazenando o valor em uma terceira matriz
 * d) mostrar todas as matrizes na tela ao final do programa
 *
 * Voce deve:
 * a) Se certificar de que os valores de linha e coluna fornecidos pelo usuario possuem
 *    a mesma ordem, caso contrario a soma nao podera ser realizada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **alocarMatriz(int linhas, int colunas)
{
    int i, j;
    float **mat = (float **) malloc(linhas * sizeof(float *));
    if (mat == NULL)
    {
        printf("Erro: falha na alocacao de memoria.\n");
        exit(1);
    }
    for (i = 0; i < linhas; i++)
    {
        mat[i] = (float *) malloc(colunas * sizeof(float));
        if (mat[i] == NULL)
        {
            printf("Erro: falha na alocacao de memoria.\n");
            for (j = 0; j < i; j++)
            {
                free(mat[j]);
            }
            free(mat);
            exit(1);
        }
    }
    return mat;
}

void liberarMatriz(float **mat, int linhas)
{
    int i;
    for (i = 0; i < linhas; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void preencherMatrizAleatoria(float **mat, int linhas, int colunas)
{
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            mat[i][j] = ((float) (rand() % 10000)) / 100.0f;
        }
    }
}

void somarMatrizes(float **a, float **b, float **c, int linhas, int colunas)
{
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void mostrarMatriz(float **mat, int linhas, int colunas, const char *nome)
{
    int i, j;
    printf("Matriz %s (%dx%d):\n", nome, linhas, colunas);
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%8.2f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int linhasA, colunasA;
    int linhasB, colunasB;
    float **A, **B, **C;

    srand((unsigned int) time(NULL));

    printf("Informe as dimensoes da matriz A.\n");
    printf("Numero de linhas de A: ");
    if (scanf("%d", &linhasA) != 1 || linhasA <= 0)
    {
        printf("Valor invalido.\n");
        return 1;
    }
    printf("Numero de colunas de A: ");
    if (scanf("%d", &colunasA) != 1 || colunasA <= 0)
    {
        printf("Valor invalido.\n");
        return 1;
    }

    printf("Informe as dimensoes da matriz B.\n");
    printf("Numero de linhas de B: ");
    if (scanf("%d", &linhasB) != 1 || linhasB <= 0)
    {
        printf("Valor invalido.\n");
        return 1;
    }
    printf("Numero de colunas de B: ");
    if (scanf("%d", &colunasB) != 1 || colunasB <= 0)
    {
        printf("Valor invalido.\n");
        return 1;
    }

    if (linhasA != linhasB || colunasA != colunasB)
    {
        printf("Erro: as matrizes possuem ordens diferentes (%dx%d e %dx%d).\n",
               linhasA, colunasA, linhasB, colunasB);
        printf("A soma nao pode ser realizada.\n");
        return 1;
    }

    A = alocarMatriz(linhasA, colunasA);
    B = alocarMatriz(linhasB, colunasB);
    C = alocarMatriz(linhasA, colunasA);

    preencherMatrizAleatoria(A, linhasA, colunasA);
    preencherMatrizAleatoria(B, linhasB, colunasB);

    somarMatrizes(A, B, C, linhasA, colunasA);

    mostrarMatriz(A, linhasA, colunasA, "A");
    mostrarMatriz(B, linhasB, colunasB, "B");
    mostrarMatriz(C, linhasA, colunasA, "C = A + B");

    liberarMatriz(A, linhasA);
    liberarMatriz(B, linhasB);
    liberarMatriz(C, linhasA);

    return 0;
}
