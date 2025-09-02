#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");

  char name[15];
  char gen;

  printf("\nQual o seu nome? ");
  scanf("%s", name);
  printf("Qual seu sexo f -  m: ");
  scanf(" %c", &gen);

  if (gen == 'f') {
    printf("Olá senhora, %s!\n", name);
  } else {
    printf("Olá senhor, %s!\n", name);
  } 
  
  

  return 0;
}
