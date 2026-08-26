#include <stdio.h>

int main() {
    int age = 24;

    if (age >= 18 && age < 70) {
        printf("obrigatorio");
    } else {
        printf("não ");
    }
    
    return 0;
}