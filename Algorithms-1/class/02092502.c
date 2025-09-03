#include<stdio.h>
#include<locale.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  int freq; 
  float media;

  printf("\n\t Teste se aprovado \t\n");

  printf("Informe a frequência: ");
  scanf("%i", &freq);
  
  if (freq >= 75) {
    printf("\n Informe a média: ");
    scanf("%f", &media);

    if (media >= 6) {
      printf("\n Aprovado!");
    } else {
      printf("Reporvado por nota");
    }
    
  } else {
    printf("\n Reprovado por frequência!");
  }
  

  return 0;
}
