#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
Faça um algoritmo que peça a idade do usuário. Se ele tiver entre 18 e
65 anos, apresentar a mensagem: “Você é obrigado a votar”. Do
contrário, apresentar a mensagem: “você não é obrigado a votar”
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int age;

  printf("\n\t Verificador de votos!");
  printf("\nInforme sua idade: ");
  scanf("%d", &age);

  if (age >= 18 || age <= 65) {
    printf("\n Você é obrigado a votar!");
  } else {
    printf("Você não é obrigado a votar!");
  }
  

  return 0;
}
