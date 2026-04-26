/*
 * Nome completo: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 *
 * Enunciado da questao:
 * Escreva um programa completo em C que:
 *   -> Crie e inicialize um vetor de numeros inteiros e liste seus valores na tela;
 *   -> Leia do teclado um numero inteiro;
 *   -> Chame a funcao implementada na primeira questao (Maiores) para obter a relacao
 *      de numeros maiores do que o valor lido do teclado;
 *   -> Liste na tela todo o conteudo da relacao obtida pela funcao chamada (Maiores)
 *      ou uma mensagem de erro, se for o caso.
 *
 * Exemplos esperados:
 *   vetor original = {7, 35, 10, 18}
 *   Digite o valor limite: 11
 *   valores maiores do que 11 = {35, 18}
 *
 *   vetor original = {7, 35, 10, 18}
 *   Digite o valor limite: 100
 *   nenhum valor maior do que 100 encontrado no vetor
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

void imprimirVetor(int *vet, int n)
{
    int i;
    printf("{");
    for (i = 0; i < n; i++)
    {
        printf("%d", vet[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("}");
}

int main()
{
    int vetor[] = {7, 35, 10, 18};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int x;
    int qtd = 0;
    int *maiores;

    printf("vetor original = ");
    imprimirVetor(vetor, n);
    printf("\n");

    printf("Digite o valor limite: ");
    if (scanf("%d", &x) != 1)
    {
        printf("Entrada invalida.\n");
        return 1;
    }

    maiores = Maiores(vetor, n, x, &qtd);

    if (maiores == NULL)
    {
        printf("nenhum valor maior do que %d encontrado no vetor\n", x);
    }
    else
    {
        printf("valores maiores do que %d = ", x);
        imprimirVetor(maiores, qtd);
        printf("\n");
        free(maiores);
    }

    return 0;
}
