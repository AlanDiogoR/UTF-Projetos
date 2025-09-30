#include <stdio.h>
#include <string.h>
#include <math.h>

/*
02) Elabore um programa em Linguagem C para apresentar ao usuário um menu com as
seguintes opções:
1 – Adição
2 – Exponenciação
3 – Divisão Simples
4 – Resto da Divisão
5 – Primeiro número é par
6 – Segundo número é ímpar
0 – Sair.
O programa deve:
- Para cada cadastro:
a) Escolher uma opção do menu;
b) Realizar a operação ou apresentar a mensagem “Opção inválida”, caso tenha escolhido uma opção
inexistente no menu;
c) Solicitar a quantidade de valores inteiros necessários para realizar a operação escolhida;
d)Apresentar o resultado da operação na tela.
A execução do programa só terminará quando o usuário digitar a opção 0 (Sair).
 Obrigatório:
- Estrutura de repetição com teste no final(do-while);
- Comando multicaso (switch-case) para a escolha do tipo de cálculo;
- Comando de seleção simples, operador de resto e funções matemáticas para realizar os
cálculos.

*/

int main()
{
  printf("Menu de Operacoes:\n");

  printf("1 - Adicao\n");
  printf("2 - Exponenciacao\n");
  printf("3 - Divisao Simples\n");
  printf("4 - Resto da Divisao\n");
  printf("5 - Primeiro numero e par\n");
  printf("6 - Segundo numero e impar\n");
  printf("0 - Sair\n");

  int opcao, n, i;
  int num1, num2;
  int resultado_int;
  float resultado_float;

  printf("Escolha uma opcao do menu: ");
  scanf("%d", &opcao);

  do
  {
    switch (opcao)
    {
    case 1: // Adição
      printf("Digite a quantidade de valores inteiros para adicao: ");
      scanf("%d", &n);
      resultado_int = 0;
      for (i = 0; i < n; i++)
      {
        int valor;
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        resultado_int += valor;
      }
      printf("Resultado da adicao: %d\n", resultado_int);
      break;
    case 2: // Exponenciação
      printf("Digite a base (inteiro): ");
      scanf("%d", &num1);
      printf("Digite o expoente (inteiro): ");
      scanf("%d", &num2);
      resultado_float = pow(num1, num2);
      printf("Resultado da exponenciacao: %.2f\n", resultado_float);
      break;
    case 3: // Divisão Simples
      printf("Digite o dividendo (inteiro): ");
      scanf("%d", &num1);
      printf("Digite o divisor (inteiro): ");
      scanf("%d", &num2);
      if (num2 != 0)
      {
        resultado_float = (float)num1 / num2;
        printf("Resultado da divisao simples: %.2f\n", resultado_float);
      }
      else
      {
        printf("Erro: Divisao por zero nao e permitida.\n");
      }
      break;
    case 4: // Resto da Divisão
      printf("Digite o dividendo (inteiro): ");
      scanf("%d", &num1);
      printf("Digite o divisor (inteiro): ");
      scanf("%d", &num2);
      if (num2 != 0)
      {
        resultado_int = num1 % num2;
        printf("Resultado do resto da divisao: %d\n", resultado_int);
      }
      else
      {
        printf("Erro: Divisao por zero nao e permitida.\n");
      }
      break;
    case 5: // Primeiro número é par
      printf("Digite o primeiro numero (inteiro): ");
      scanf("%d", &num1);
      if (num1 % 2 == 0)
      {
        printf("O primeiro numero %d e par.\n", num1);
      }
      else
      {
        printf("O primeiro numero %d nao e par.\n", num1);
      }
      break;
    case 6: // Segundo número é ímpar
      printf("Digite o segundo numero (inteiro): ");
      scanf("%d", &num2);
      if (num2 % 2 != 0)
      {
        printf("O segundo numero %d e impar.\n", num2);
      }
      else
      {
        printf("O segundo numero %d nao e impar.\n", num2);
      }
      break;
    case 0: // Sair
      printf("Saindo do programa.\n");
      break;

    default:
      break;
    }

  } while (opcao != 0);
}
