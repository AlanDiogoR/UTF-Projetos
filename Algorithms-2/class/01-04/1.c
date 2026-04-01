#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor;
    int quantidade, i;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &quantidade);
    // Alocação dinâmica de memória para o vetor
    vetor = (int *)malloc(quantidade * sizeof(int));

    for (i = 0; i < quantidade; i++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor digitado:\n");
    for (i = 0; i < quantidade; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    // Liberação da memória alocada
    free(vetor);
    return 0;   
        
}