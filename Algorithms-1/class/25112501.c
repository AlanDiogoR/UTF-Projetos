#include <stdio.h>

void menu();
void handleEscolha(int opcao);
void handleApresentar(float result, int opcao);

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;

    do
    {
        printf(" 1 - IMC\n");
        printf(" 2 - TMB\n");
        printf(" 0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        handleEscolha(opcao);

    } while (opcao != 0);


}

void handleEscolha(int opcao) {
    float peso, altura, imc, tmb, idade;
    char sexo;

    switch (opcao)
    {
    case 1:
        printf("Digite seu peso (kg): ");
        scanf("%f", &peso);
        printf("Digite sua altura (m): ");
        scanf("%f", &altura);

        imc = peso / (altura * altura);

        handleApresentar(imc, opcao);

        break;

    case 2:
        printf("Digite seu peso (kg): ");
        scanf("%f", &peso);
        printf("Digite sua altura (cm): ");
        scanf("%f", &altura);
        printf("Digite sua idade (anos): ");
        scanf("%f", &idade);
        printf("Digite seu sexo (M/F): ");
        scanf(" %c", &sexo);

        if (sexo == 'M' || sexo == 'm') {
            tmb = 88.36 + (13.4 * peso) + (4.8 * altura) - (5.7 * idade);
        } else if (sexo == 'F' || sexo == 'f') {
            tmb = 447.6 + (9.2 * peso) + (3.1 * altura) - (4.3 * idade);
        } else {
            printf("Sexo invalido!\n");
            return;
        }

        handleApresentar(tmb, opcao);
        break;

    case 0:
        printf("Saindo...\n");
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }
}

void handleApresentar(float result, int opcao) {
    if (opcao == 1) {
        printf("+---------------------+\n");
        printf("| Seu IMC e: %.2f     |\n", result);
        printf("+---------------------+\n");
    } else if (opcao == 2) {
        printf("+-------------------------+\n");
        printf("| Sua TMB e: %.2f kcal/dia |\n", result);
        printf("+-------------------------+\n");
    }
}
