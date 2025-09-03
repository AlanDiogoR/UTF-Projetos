#include<stdio.h>
#include<locale.h>
#include<string.h>

/*
Faça um algoritmo que peça o usuário e senha. Se o usuário for “chefe”
e a senha for “123456”, então apresentar a mensagem “login realizado”.
Do contrário, apresentar a mensagem “usuário e/ou senha incorretos”.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  char user[15];
  int password;

  printf("\n\t Login \t");

  printf("\nInforme o usuário: ");
  gets(user);
  printf("\n Informe a senha (numérica): ");
  scanf("%d", &password);

  if ( strcmp(user, "chefe") == 0 && password == 123456) {
    printf("\n Login realizado com sucesso!");
  } else {
    printf("Usuário e/ou snehas incorrretos!");
  }

  return 0;
}
