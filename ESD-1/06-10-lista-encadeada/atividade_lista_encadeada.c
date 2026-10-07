#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
} Lista;

Lista *inicializa(void) {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l == NULL) {
        return NULL;
    }

    l->inicio = NULL;
    return l;
}

int insere(Lista *l, int valor) {
    No *novo;

    if (l == NULL) {
        return 0;
    }

    novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = l->inicio;
    l->inicio = novo;

    return 1;
}

void imprime(const Lista *l) {
    No *p;

    if (l == NULL) {
        printf("Lista invalida.\n");
        return;
    }

    p = l->inicio;
    printf("Lista: ");

    while (p != NULL) {
        printf("%d ", p->valor);
        p = p->prox;
    }

    printf("\n");
}

int vazia(const Lista *l) {
    return (l == NULL || l->inicio == NULL) ? 1 : 0;
}

int quantidade(const Lista *l) {
    int qtd = 0;
    No *p;

    if (l == NULL) {
        return 0;
    }

    p = l->inicio;
    while (p != NULL) {
        qtd++;
        p = p->prox;
    }

    return qtd;
}

int soma(const Lista *l) {
    int total = 0;
    No *p;

    if (l == NULL) {
        return 0;
    }

    p = l->inicio;
    while (p != NULL) {
        total += p->valor;
        p = p->prox;
    }

    return total;
}

No *busca(const Lista *l, int valor) {
    No *p;

    if (l == NULL) {
        return NULL;
    }

    p = l->inicio;
    while (p != NULL) {
        if (p->valor == valor) {
            return p;
        }
        p = p->prox;
    }

    return NULL;
}

int maior(const Lista *l) {
    int maiorValor;
    No *p;

    if (vazia(l)) {
        return INT_MIN;
    }

    p = l->inicio;
    maiorValor = p->valor;

    p = p->prox;
    while (p != NULL) {
        if (p->valor > maiorValor) {
            maiorValor = p->valor;
        }
        p = p->prox;
    }

    return maiorValor;
}

void libera(Lista *l) {
    No *p;
    No *prox;

    if (l == NULL) {
        return;
    }

    p = l->inicio;
    while (p != NULL) {
        prox = p->prox;
        free(p);
        p = prox;
    }

    free(l);
}

int main(void) {
    Lista *l;
    No *encontrado;

    l = inicializa();
    if (l == NULL) {
        printf("Erro ao inicializar lista.\n");
        return 1;
    }

    insere(l, 10);
    insere(l, 20);
    insere(l, 5);

    imprime(l);
    printf("Lista vazia? %d\n", vazia(l));
    printf("Quantidade de elementos: %d\n", quantidade(l));
    printf("Soma dos valores: %d\n", soma(l));

    encontrado = busca(l, 10);
    if (encontrado != NULL) {
        printf("Valor 10 encontrado no no: %p\n", (void *)encontrado);
    } else {
        printf("Valor 10 nao encontrado.\n");
    }

    if (!vazia(l)) {
        printf("Maior valor: %d\n", maior(l));
    }

    libera(l);
    return 0;
}
