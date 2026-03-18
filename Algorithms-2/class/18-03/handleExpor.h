#include <stdio.h>

void preencheVetor(int v[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        v[i] = i + 1;
    }
}

void imprimeVetor(int v[], int tam) {
    int i;
    
    for (i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
}


