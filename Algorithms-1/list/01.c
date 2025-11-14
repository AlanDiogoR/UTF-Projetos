#include <stdio.h>
#include <stdlib.h>

#define TAM20 20
#define TAM10 10
#define TAM8 8
#define TAM5 5
#define TAM100 100

int main()
{
  int opcao;
  char continuar;

  do
  {
    printf("\n==================== MENU ====================\n");
    printf("1 - Ler e mostrar 20 numeros inteiros\n");
    printf("2 - Maior elemento e posicao (20 numeros)\n");
    printf("3 - Contar quantos menores que 10 (10 numeros)\n");
    printf("4 - Mostrar 10 numeros na ordem inversa\n");
    printf("5 - Digitar 8 numeros e mostrar suas posicoes\n");
    printf("6 - Procurar um numero dentro de vetor (8 numeros)\n");
    printf("7 - Preencher vetor com numeros pares de 2 a 20\n");
    printf("8 - Somar vetores de 5 posicoes\n");
    printf("9 - Procurar numero em vetor de 10 numeros nao repetidos\n");
    printf("10 - Vetor de 100 elementos: 1=par / 0=impar\n");
    printf("11 - Vetor de 20 numeros impares positivos (multiplos de 5, posicoes pares...)\n");
    printf("==============================================\n");
    printf("Escolha uma opcao (1 a 11): ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    {
      int v[TAM20];
      printf("\nDigite %d numeros inteiros positivos:\n", TAM20);
      for (int i = 0; i < TAM20; i++)
      {
        scanf("%d", &v[i]);
      }
      printf("\nElementos digitados:\n");
      for (int i = 0; i < TAM20; i++)
      {
        printf("%d ", v[i]);
      }
      printf("\n");
      break;
    }

    case 2:
    {
      int v[TAM20], maior, pos;
      printf("\nDigite %d numeros inteiros positivos:\n", TAM20);
      for (int i = 0; i < TAM20; i++)
      {
        scanf("%d", &v[i]);
      }
      maior = v[0];
      pos = 0;
      for (int i = 1; i < TAM20; i++)
      {
        if (v[i] > maior)
        {
          maior = v[i];
          pos = i;
        }
      }
      printf("Maior numero: %d na posicao %d\n", maior, pos);
      break;
    }

    case 3:
    {
      int v[TAM10], cont = 0;
      printf("\nDigite %d numeros:\n", TAM10);
      for (int i = 0; i < TAM10; i++)
      {
        scanf("%d", &v[i]);
        if (v[i] < 10)
          cont++;
      }
      printf("Quantidade de numeros menores que 10: %d\n", cont);
      break;
    }

    case 4:
    {
      int v[TAM10];
      printf("\nDigite %d numeros:\n", TAM10);
      for (int i = 0; i < TAM10; i++)
      {
        scanf("%d", &v[i]);
      }
      printf("Ordem inversa:\n");
      for (int i = TAM10 - 1; i >= 0; i--)
      {
        printf("%d ", v[i]);
      }
      printf("\n");
      break;
    }

    case 5:
    {
      int v[TAM8];
      for (int i = 0; i < TAM8; i++)
      {
        printf("Digite o numero para a posicao [%d]: ", i);
        scanf("%d", &v[i]);
      }
      printf("\nNumeros digitados:\n");
      for (int i = 0; i < TAM8; i++)
      {
        printf("Posicao [%d] = %d\n", i, v[i]);
      }
      break;
    }

    case 6:
    {
      int v[TAM8], num, achou = 0;
      printf("\nDigite %d numeros:\n", TAM8);
      for (int i = 0; i < TAM8; i++)
      {
        scanf("%d", &v[i]);
      }
      printf("Digite um numero para procurar: ");
      scanf("%d", &num);
      for (int i = 0; i < TAM8; i++)
      {
        if (v[i] == num)
        {
          printf("Numero encontrado na posicao [%d]\n", i);
          achou = 1;
        }
      }
      if (!achou)
        printf("Numero nao encontrado no vetor.\n");
      break;
    }

    case 7:
    {
      int v[TAM10];
      for (int i = 0; i < TAM10; i++)
      {
        v[i] = (i + 1) * 2;
      }
      printf("Numeros pares de 2 a 20:\n");
      for (int i = 0; i < TAM10; i++)
      {
        printf("%d ", v[i]);
      }
      printf("\n");
      break;
    }

    case 8:
    {
      int v1[TAM5], v2[TAM5], soma[TAM5];
      printf("Digite 5 numeros para o vetor 1:\n");
      for (int i = 0; i < TAM5; i++)
        scanf("%d", &v1[i]);
      printf("Digite 5 numeros para o vetor 2:\n");
      for (int i = 0; i < TAM5; i++)
        scanf("%d", &v2[i]);
      printf("Soma das mesmas posicoes:\n");
      for (int i = 0; i < TAM5; i++)
      {
        soma[i] = v1[i] + v2[i];
        printf("[%d] + [%d] = %d\n", v1[i], v2[i], soma[i]);
      }
      break;
    }

    case 9:
    {
      int v[TAM10], num, achou = 0;
      printf("Digite %d numeros NAO repetidos:\n", TAM10);
      for (int i = 0; i < TAM10; i++)
        scanf("%d", &v[i]);
      printf("Digite um numero para procurar: ");
      scanf("%d", &num);
      for (int i = 0; i < TAM10; i++)
      {
        if (v[i] == num)
        {
          printf("Numero encontrado na posicao [%d]\n", i);
          achou = 1;
        }
      }
      if (!achou)
        printf("O numero nao foi encontrado no vetor.\n");
      break;
    }

    case 10:
    {
      int v[TAM100];
      for (int i = 0; i < TAM100; i++)
      {
        if (i % 2 == 0)
          v[i] = 1;
        else
          v[i] = 0;
      }
      printf("Vetor de 1 (par) e 0 (impar):\n");
      for (int i = 0; i < TAM100; i++)
      {
        printf("%d ", v[i]);
      }
      printf("\n");
      break;
    }

    case 11:
    {
      int v[TAM20], multiplos5[TAM20], cont5 = 0;
      printf("Digite %d numeros impares e positivos:\n", TAM20);
      for (int i = 0; i < TAM20; i++)
      {
        do
        {
          scanf("%d", &v[i]);
          if (v[i] <= 0 || v[i] % 2 == 0)
            printf("Numero invalido, digite um impar e positivo: ");
        } while (v[i] <= 0 || v[i] % 2 == 0);
      }
      printf("\nMultiplos de 5: ");
      for (int i = 0; i < TAM20; i++)
      {
        if (v[i] % 5 == 0)
        {
          printf("%d ", v[i]);
          multiplos5[cont5++] = v[i];
        }
      }
      printf("\nQuantidade de multiplos de 5: %d\n", cont5);

      printf("Numeros nas posicoes pares: ");
      for (int i = 0; i < TAM20; i += 2)
        printf("%d ", v[i]);

      printf("\nVetor original:\n");
      for (int i = 0; i < TAM20; i++)
        printf("%d ", v[i]);
      printf("\n");
      break;
    }

    default:
      printf("Opcao invalida.\n");
    }

    printf("\nDeseja continuar? (s/n): ");
    scanf(" %c", &continuar);

  } while (continuar == 's' || continuar == 'S');

  printf("\nPrograma encerrado.\n");
  return 0;
}
