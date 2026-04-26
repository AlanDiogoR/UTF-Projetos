/*
 * Nome completo: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 *
 * Enunciado da questao:
 * Escreva um programa em Linguagem C que:
 * a) Aloque dinamicamente um vetor de inteiros com dimensao 10;
 * b) Obtenha uma sequencia indefinida de numeros inteiros maiores do que zero (0) e:
 *      i.  Cada numero digitado deve ser armazenado no vetor criado no item a);
 *      ii. Se o usuario digitar mais de 10 numeros, o programa deve realocar espaco de
 *          memoria para o vetor, suficiente para armazenar mais 10 numeros inteiros, e
 *          assim sucessivamente ate que a sequencia de numeros seja finalizada;
 *      iii.Esta sequencia e finalizada quando o usuario digitar 0 (zero)
 *          (o valor 0 nao deve ser armazenado);
 * c) No final, todos os dados digitados e armazenados no vetor deverao ser mostrados na tela;
 * d) Utilize funcoes para:
 *      i.   Alocar o vetor
 *      ii.  Realocar o vetor
 *      iii. Mostrar o conteudo do vetor
 */

#include <stdio.h>
#include <stdlib.h>

#define BLOCO 10

int *alocarVetor(int tamanho)
{
    int *vet = (int *) malloc(tamanho * sizeof(int));
    if (vet == NULL)
    {
        printf("Erro: falha na alocacao de memoria.\n");
        exit(1);
    }
    return vet;
}

int *realocarVetor(int *vet, int novoTamanho)
{
    int *novo = (int *) realloc(vet, novoTamanho * sizeof(int));
    if (novo == NULL)
    {
        printf("Erro: falha na realocacao de memoria.\n");
        free(vet);
        exit(1);
    }
    return novo;
}

void mostrarVetor(int *vet, int qtd)
{
    int i;
    if (qtd == 0)
    {
        printf("Nenhum numero foi digitado.\n");
        return;
    }
    printf("Valores armazenados no vetor:\n");
    for (i = 0; i < qtd; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main()
{
    int *vet;
    int qtd = 0;
    int capacidade = BLOCO;
    int numero;

    vet = alocarVetor(capacidade);

    printf("Digite numeros inteiros maiores do que zero (0 para encerrar):\n");

    while (1)
    {
        printf("Numero %d: ", qtd + 1);
        if (scanf("%d", &numero) != 1)
        {
            printf("Entrada invalida. Encerrando.\n");
            break;
        }

        if (numero == 0)
        {
            break;
        }

        if (numero < 0)
        {
            printf("Ignorado: apenas numeros maiores do que zero sao aceitos.\n");
            continue;
        }

        if (qtd == capacidade)
        {
            capacidade += BLOCO;
            vet = realocarVetor(vet, capacidade);
        }

        vet[qtd] = numero;
        qtd++;
    }

    mostrarVetor(vet, qtd);

    free(vet);
    return 0;
}
