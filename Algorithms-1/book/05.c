#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
Imagine que em um determinado país, os homens podem se aposentar
se tiverem trabalhado pelo menos 30 anos e tenham mais de 65 anos. E,
no caso das mulheres, elas podem se aposentar se tiverem trabalhado
pelo menos 25 anos e tenham mais de 60 anos. Reparem que foi usado
E no enunciado, então, deve-se seguir a risca o que foi pedido. Faça um
algoritmo que peça o gênero, a idade e tempo de contribuição. Em
seguida, o algoritmo deve apresentar se a pessoa pode ou não se
aposentar.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int age, yearsWork;
  char gen[1];

  printf("\n\t Verificar aposentadoria!");
  printf("\n Informe o genêro(f ou m): ");
  gets(gen);
  printf("\nInforme a idade: ");
  scanf("%d", &age);
  printf("\nInforme os anos trabalhados: ");
  scanf("%d", &yearsWork);

  if ( strcmp(gen, "m") == 0) {

    if (age > 65 && yearsWork >= 30) {
      printf("\nVocê já pode aposentar!");
    } else {
      printf("Ainda não pode aposentar!");
    }

  } else {

    if (age > 60 && yearsWork >= 25) {
      printf("\nVocê já pode aposentar!");
    } else {
      printf("Ainda não pode aposentar!");
    }
  }


  return 0;
}
