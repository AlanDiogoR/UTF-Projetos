/*
 * Nome completo: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 *
 * Enunciado da questao:
 * Implemente, na linguagem de programacao C, uma funcao que tenha o seguinte prototipo:
 *   int *Maiores (int *vet, int n, int x, int *qtd);
 *
 * Essa funcao recebe os seguintes parametros:
 *   -> vet: um vetor de numeros inteiros
 *   -> n: a quantidade de elementos do vetor vet
 *   -> x: um numero inteiro
 *
 * Essa funcao deve:
 *   -> Verificar a quantidade de elementos do vetor que sejam maiores do que x
 *   -> Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma area do
 *      exato tamanho necessario para armazenar esta quantidade de valores
 *   -> Copiar os elementos do vetor que sejam maiores do que x para o vetor alocado
 *      dinamicamente
 *
 * Essa funcao retorna:
 *   -> o ponteiro para a area alocada dinamicamente, preenchida com os numeros maiores
 *      do que x, ou NULL, caso essa relacao de numeros nao tenha sido criada.
 *
 * Ha tambem:
 *   -> a quantidade de numeros carregados na area alocada dinamicamente, atraves do
 *      ponteiro qtd.
 */

#include <stdio.h>
#include <stdlib.h>

int *Maiores(int *vet, int n, int x, int *qtd)
{
    int i, j;
    int *resultado;

    *qtd = 0;

    for (i = 0; i < n; i++)
    {
        if (vet[i] > x)
        {
            (*qtd)++;
        }
    }

    if (*qtd == 0)
    {
        return NULL;
    }

    resultado = (int *) malloc((*qtd) * sizeof(int));
    if (resultado == NULL)
    {
        *qtd = 0;
        return NULL;
    }

    j = 0;
    for (i = 0; i < n; i++)
    {
        if (vet[i] > x)
        {
            resultado[j] = vet[i];
            j++;
        }
    }

    return resultado;
}
