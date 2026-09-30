#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserirInicio(No **inicio, int valor) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Falha ao alocar memoria.\n");
        return;
    }

    novo->valor = valor;
    novo->prox = *inicio;
    *inicio = novo;
}

void imprimir(No *inicio) {
    No *atual = inicio;

    printf("inicio -> ");

    while (atual != NULL) {
        printf("[%d] -> ", atual->valor);
        atual = atual->prox;
    }

    printf("NULL\n");
}

void liberar(No *inicio) {
    No *atual = inicio;

    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main(void) {
    No *lista = NULL;

    inserirInicio(&lista, 30);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 10);

    imprimir(lista);
    liberar(lista);

    return 0;
}
