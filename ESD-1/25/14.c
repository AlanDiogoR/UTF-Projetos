#include <stdio.h>

int main() {
    int n1 = 33;
    int n2 = 543;

    if (n1 < n2) {
        printf("o numero %d é menor que o %d", n1, n2);
    } else {
        printf("o numero %d é menor que o %d", n2, n1);
    }
    return 0;
}