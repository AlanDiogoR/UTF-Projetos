#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  char name[15];
  char gen;

  printf("Qual o seu nome? ");
  scanf(" %[^/]", name);
  printf("Qual seu sexo f -  m: ");
  scanf(" %c", gen);

  if (gen == 'f'  || gen == 'F') {
    printf("Olá senhora %c", name);
  }
  

  return 0;
}
