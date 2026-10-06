#include <stdio.h>
#include <stdlib.h>

/* 1. Struct do nó */
typedef struct no {
    int valor;
    struct no *prox;
} No;

/* Estrutura da lista */
typedef struct lista {
    No *inicio;
} Lista;

/* 2. Inicializa lista vazia */
Lista* inicializa() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

/* 3. Insere no início da lista */
void insere(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
}

/* 5. Imprime todos os elementos */
void imprime(Lista *l) {
    No *p = l->inicio;

    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
}

/* 6. Verifica se a lista está vazia */
int vazia(Lista *l) {
    if (l->inicio == NULL)
        return 1;

    return 0;
}

/* 7. Quantidade de elementos */
int quantidade(Lista *l) {
    int cont = 0;
    No *p = l->inicio;

    while (p != NULL) {
        cont++;
        p = p->prox;
    }

    return cont;
}

/* 8. Soma dos valores */
int soma(Lista *l) {
    int total = 0;
    No *p = l->inicio;

    while (p != NULL) {
        total += p->valor;
        p = p->prox;
    }

    return total;
}

/* 9. Busca valor na lista */
No* busca(Lista *l, int valor) {
    No *p = l->inicio;

    while (p != NULL) {
        if (p->valor == valor)
            return p;

        p = p->prox;
    }

    return NULL;
}

/* 10. Retorna o maior valor */
int maior(Lista *l) {
    if (l->inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;
    }

    No *p = l->inicio;
    int maior = p->valor;

    while (p != NULL) {
        if (p->valor > maior)
            maior = p->valor;

        p = p->prox;
    }

    return maior;
}

/* Programa principal */
int main() {

    /* 4. Código solicitado */
    Lista *l;

    l = inicializa();
    insere(l, 10);
    insere(l, 20);

    printf("Elementos da lista: ");
    imprime(l);

    printf("Lista vazia? %d\n", vazia(l));
    printf("Quantidade: %d\n", quantidade(l));
    printf("Soma: %d\n", soma(l));
    printf("Maior valor: %d\n", maior(l));

    No *encontrado = busca(l, 10);

    if (encontrado != NULL)
        printf("Valor 10 encontrado!\n");
    else
        printf("Valor 10 nao encontrado!\n");

    return 0;
}