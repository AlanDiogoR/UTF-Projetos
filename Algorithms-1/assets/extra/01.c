#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
O coração humano bate em média uma vez por segundo. Desenvolva um algoritmo para calcular e escrever quantas vezes o
coração de uma pessoa baterá se viver X anos. Dado de entrada: idade da pessoa (inteiro em anos). Considerações: 1 ano = 365,25
dias, 1 dia = 24 horas, 1 hora = 60 minutos e 1 minuto = 60 segundos.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int idade, anos;
  double batimentos;

  printf("\nInforme a sua idade em anos: ");
  scanf("%d", &idade);
  printf("\nInforme quantos anos quer viver: ");
  scanf("%d", &anos);


  batimentos = idade * 365.25 * 24 * 60 * 60;

  printf("\nSeu coração bateu aproximadamente %.0f vezes.", batimentos);
  batimentos = anos * 365.25 * 24 * 60 * 60;
  printf("\nSe você viver %d anos, seu coração baterá aproximadamente %.0f vezes.", anos, batimentos);

  return 0;
}
