#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  
  char category[6], curs[20], discipline[5], turma[6];

  printf("\n \t Descubra se você é aluno da DRa Adriane");

  printf("\nCategoria: ");
  gets(category);
  printf("\nCurso: ");
  gets(curs);
  printf("\nDisciplina: ");
  gets(discipline);
  printf("\nTurma: ");
  gets(turma);

  if( (strcmp(category, "aluno") == 0  || strcmp(curs, "ES") == 0 ) || strcmp(discipline, ""));{
    printf("Você é aluno da Utfpr");
  }

  return 0;
}
