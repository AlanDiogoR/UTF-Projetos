#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM15 15
#define TAM100 100
#define TAM10 10
#define TAM8 8
#define TAM5 5

int main()
{
  int opcao;
  char continuar;
  srand(time(NULL)); // inicializa o gerador aleatório uma única vez

  do
  {
    printf("\n================ MENU =================\n");
    printf("1 - Vetor de 15 numeros sem repeticao e contagem de negativos\n");
    printf("2 - Vetor de 100 pesos (gramas) aleatorios\n");
    printf("3 - Vetor com preco de 10 produtos sem repeticao (par/ímpar)\n");
    printf("4 - Vetor IDADE: identificar o aluno mais idoso\n");
    printf("5 - Ler 8 numeros e mostrar em ordem decrescente\n");
    printf("6 - Vetor de 100 numeros aleatorios e busca de numero\n");
    printf("7 - Dois vetores (pares 2-20 e aleatorios >20) + vetor soma\n");
    printf("=======================================\n");
    printf("Escolha uma opcao (1 a 7): ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    // ---------------------------------------------------
    case 1:
    {
      int v[TAM15];
      int negativos = 0;
      int repetido, num;

      for (int i = 0; i < TAM15; i++)
      {
        do
        {
          repetido = 0;
          num = (rand() % 201) - 100; // gera entre -100 e 100

          for (int j = 0; j < i; j++)
          {
            if (v[j] == num)
            {
              repetido = 1;
              break;
            }
          }
        } while (repetido);

        v[i] = num;
        if (v[i] < 0)
          negativos++;
      }

      printf("\nVetor NUMERO:\n");
      for (int i = 0; i < TAM15; i++)
        printf("%d ", v[i]);

      printf("\nQuantidade de valores negativos: %d\n", negativos);
      break;
    }

    // ---------------------------------------------------
    case 2:
    {
      int v[TAM100];
      int menor = 999999, pos = 0;

      for (int i = 0; i < TAM100; i++)
      {
        v[i] = rand() % 80000 + 1000; // pesos entre 1000g e 81000g
        if (v[i] < menor)
        {
          menor = v[i];
          pos = i;
        }
      }

      printf("\nVetor PESO (em gramas):\n");
      for (int i = 0; i < TAM100; i++)
        printf("%d ", v[i]);

      printf("\n\nMenor peso: %d g (colaborador posicao %d)\n", menor, pos);

      printf("\nPESO em ordem decrescente:\n");
      for (int i = TAM100 - 1; i >= 0; i--)
        printf("%d ", v[i]);
      printf("\n");
      break;
    }

    // ---------------------------------------------------
    case 3:
    {
      int v[TAM10], num, repetido;

      for (int i = 0; i < TAM10; i++)
      {
        do
        {
          repetido = 0;
          num = rand() % 90 + 10; // preços aleatórios de 10 a 99
          for (int j = 0; j < i; j++)
          {
            if (v[j] == num)
              repetido = 1;
          }
        } while (repetido);
        v[i] = num;
      }

      printf("\nPreco dos 10 produtos:\n");
      for (int i = 0; i < TAM10; i++)
      {
        printf("Produto %d: R$%d - %s\n",
               i, v[i], (v[i] % 2 == 0) ? "PAR" : "IMPAR");
      }
      break;
    }

    // ---------------------------------------------------
    case 4:
    {
      int qtd, maisVelho = 0, pos = 0;
      printf("\nDigite o numero de alunos: ");
      scanf("%d", &qtd);

      int idade[qtd];

      for (int i = 0; i < qtd; i++)
      {
        printf("Idade do aluno %d: ", i);
        scanf("%d", &idade[i]);
        if (idade[i] > maisVelho)
        {
          maisVelho = idade[i];
          pos = i;
        }
      }

      printf("\nAluno mais idoso: idade %d (posicao %d)\n", maisVelho, pos);
      break;
    }

    // ---------------------------------------------------
    case 5:
    {
      int v[TAM8], temp;

      for (int i = 0; i < TAM8; i++)
      {
        printf("Digite um numero para a posicao [%d]: ", i);
        scanf("%d", &v[i]);
      }

      // Ordena em ordem decrescente (bubble sort simples)
      for (int i = 0; i < TAM8 - 1; i++)
      {
        for (int j = i + 1; j < TAM8; j++)
        {
          if (v[i] < v[j])
          {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
          }
        }
      }

      printf("\nNumeros em ordem decrescente:\n");
      for (int i = 0; i < TAM8; i++)
        printf("%d ", v[i]);
      printf("\n");
      break;
    }

    // ---------------------------------------------------
    case 6:
    {
      int v[TAM100], num, achou = 0;

      for (int i = 0; i < TAM100; i++)
      {
        v[i] = rand() % 500; // 0 a 499
      }

      printf("\nDigite um numero para procurar: ");
      scanf("%d", &num);

      for (int i = 0; i < TAM100; i++)
      {
        if (v[i] == num)
        {
          printf("Numero encontrado na posicao [%d]\n", i);
          achou = 1;
        }
      }

      if (!achou)
        printf("Que pena!! Numero nao encontrado no vetor.\n");

      break;
    }

    // ---------------------------------------------------
    case 7:
    {
      int v1[TAM5], v2[TAM5], soma[TAM5];

      for (int i = 0; i < TAM5; i++)
        v1[i] = (i + 1) * 2; // pares de 2 a 10

      for (int i = 0; i < TAM5; i++)
        v2[i] = rand() % 80 + 21; // aleatórios > 20

      // Ordenar v1 em ordem crescente
      for (int i = 0; i < TAM5 - 1; i++)
      {
        for (int j = i + 1; j < TAM5; j++)
        {
          if (v1[i] > v1[j])
          {
            int temp = v1[i];
            v1[i] = v1[j];
            v1[j] = temp;
          }
        }
      }

      // Ordenar v2 em ordem decrescente
      for (int i = 0; i < TAM5 - 1; i++)
      {
        for (int j = i + 1; j < TAM5; j++)
        {
          if (v2[i] < v2[j])
          {
            int temp = v2[i];
            v2[i] = v2[j];
            v2[j] = temp;
          }
        }
      }

      // Soma
      for (int i = 0; i < TAM5; i++)
        soma[i] = v1[i] + v2[i];

      printf("\nVetor 1 (pares crescentes): ");
      for (int i = 0; i < TAM5; i++)
        printf("%d ", v1[i]);

      printf("\nVetor 2 (aleatorios >20 decrescentes): ");
      for (int i = 0; i < TAM5; i++)
        printf("%d ", v2[i]);

      printf("\nVetor Soma: ");
      for (int i = 0; i < TAM5; i++)
        printf("%d ", soma[i]);
      printf("\n");
      break;
    }

    // ---------------------------------------------------
    default:
      printf("Opcao invalida!\n");
    }

    printf("\nDeseja continuar? (s/n): ");
    scanf(" %c", &continuar);

  } while (continuar == 's' || continuar == 'S');

  printf("\nPrograma encerrado.\n");
  return 0;
}
