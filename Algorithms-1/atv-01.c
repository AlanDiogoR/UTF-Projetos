#include <stdio.h> 
#include <math.h>

int main() {

  int opcao;
  char continuar;

  do {

    printf("\n *****  Lista de Exercicios  ***** \n");
    printf("\n Ao final do programa informar apenas s para continuar \n");
    printf("\nEscolha uma opcao de 1 a 9: ");
    scanf("%d", &opcao);

    switch (opcao){
    case 1: {
      //média notas
      float n1,n2,n3,n4,media;

      printf("Informe a primeira nota: ");
      scanf("%f", &n1);
      printf("Informe a segunda nota: ");
      scanf("%f", &n2);
      printf("Informe a terceira nota: ");
      scanf("%f", &n3);
      printf("Informe a quarta nota: ");
      scanf("%f", &n4);

      media = (n1+n2+n3+n4)/4;

      printf("A média do aluno é: %.2f \n", media);

    } 

    case 2: {
      //02 area circunferencia
      float raio, area;

      printf("Informe o raio da circunferencia: ");
      scanf("%f", &raio);

      area = M_PI * raio * raio;

      printf("A area da circunferencia e: %2.f\n", area);

    }

    default:
      printf("Questão invalida!\n");
    }

  } while(continuar == 's' || continuar == 'S');
}