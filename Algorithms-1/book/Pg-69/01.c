#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Imagine um parque infantil. Faça um algoritmo que peça a altura do usuário e a
idade.
a. Se tiver altura menor que 1,6m, pode entrar no parque. Neste caso:
i. Se tiver menos de 5 anos, escreva a mensagem: “Pode brincar no
pula-pula e Casinha”;
ii. Se tiver entre 5 e 8 anos, escreva a mensagem: “Pode brincar na
prancha do pirata e piscina de bolinhas”.
iii. Se tiver mais de 8 anos, escreva a mensagem: “Pode brincar de
pebolim, ping-pong e basquete”.
b. Se tiver altura maior ou igual a 1,6m, escreva a mensagem: “Você é muito
grande para entrar no parque”.

*/

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int idade;
  float altura;

  printf("\n\t  Parque infantil!");

  printf("\nInforme sua idade: ");
  scanf("%d", &idade);
  printf("\nInforme sua altura: ");
  scanf("%f", &altura);

  if (altura < 1.6)
  {

    if (idade < 5)
    {
      printf("Pode brincar no pula pula e casinha!");
    }
    else if (idade >= 5 || idade < 9)
    {
      printf("Pode brincar na prancha do pirata e na pscina de bolinhas!");
    }
    else
    {
      printf("Pode brincar de pebolim, ping-pong e basquete");
    }
  }
  else
  {
    printf("Você é muito grande para entrar no parque ");
  }

  return 0;
}
