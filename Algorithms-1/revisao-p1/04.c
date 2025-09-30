#include <stdio.h>
#include <string.h>
#include <math.h>

/*
03) Elabore um programa em Linguagem C para permitir o cadastro de N alunos, onde N
será informado pelo usuário. O aluno só poderá ser considerado “apto” para doação de
sangue se tiver 18 anos ou mais e; não possuir nenhuma doença que inviabilize a doação.
O programa deve:
- Para cada cadastro, exibir:
a) Uma mensagem indicando se o aluno pode ou não ser doador de sangue.
- Ao final da execução do programa, exibir:
b) o total de alunos cadastrados e o número de alunos aptos para doação de sangue.
 Obrigatório:
- Estrutura de repetição for;
- if aninhado (if dentro de if) para verificar a idade e se possui alguma doença que impeça
a doação de sangue, por meio, de uma variável do tipo cadeia.
- Comando de comparação de string (strcmp);
*/

int main()
{
  int N, idade, total_aptos = 0;
  char possui_doenca[4];

  printf("Cadastro de Alunos para Doacao de Sangue\n");
  printf("Digite o numero de alunos a serem cadastrados: ");
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    printf("Aluno %d:\n", i + 1);
    printf("Digite a idade do aluno: ");
    scanf("%d", &idade);
    printf("O aluno possui alguma doenca que inviabilize a doacao? (Sim ou Nao): ");
    scanf("%s", possui_doenca);

    if (idade >= 18)
    {
      if (strcmp(possui_doenca, "Nao") == 0 || strcmp(possui_doenca, "nao") == 0)
      {
        printf("O aluno pode ser doador de sangue.\n");
        total_aptos++;
      }
      else
      {
        printf("O aluno nao pode ser doador de sangue devido a doenca.\n");
      }
    }
    else
    {
      printf("O aluno nao pode ser doador de sangue devido a idade.\n");
    }
  }
  printf("Total de alunos cadastrados: %d\n", N);
  printf("Numero de alunos aptos para doacao de sangue: %d\n", total_aptos);
  return 0;
}
