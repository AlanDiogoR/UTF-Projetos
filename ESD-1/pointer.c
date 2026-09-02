#include <stdio.h>

int main() {

    int a = 5;
    int *p = &a;
    int arr[3] = {1, 2, 3};
    int *p = arr;

    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", &a);
    printf("Valor através do ponteiro: %d\n", *p);

    *p = 20; // altera o valor de a

    printf("Novo valor de a: %d\n", a);

    printf("%d\n", *(p+1))

    return 0;
}