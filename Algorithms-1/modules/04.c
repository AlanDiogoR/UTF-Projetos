#include <stdio.h>

void soma()
{
  float a, b, resultado;
  printf("Digite dois valores para soma:\n");
  scanf("%f %f", &a, &b);
  resultado = a + b;
  printf("Resultado da soma: %.2f\n", resultado);
}

void subtracao()
{
  float a, b, resultado;
  printf("Digite dois valores para subtração:\n");
  scanf("%f %f", &a, &b);
  resultado = a - b;
  printf("Resultado da subtração: %.2f\n", resultado);
}

void divisao()
{
  float a, b, resultado;
  printf("Digite dois valores para divisão:\n");
  scanf("%f %f", &a, &b);
  if (b != 0)
  {
    resultado = a / b;
    printf("Resultado da divisão: %.2f\n", resultado);
  }
  else
  {
    printf("Erro: Divisão por zero não é permitida.\n");
  }
}

void multiplicacao()
{
  float a, b, resultado;
  printf("Digite dois valores para multiplicação:\n");
  scanf("%f %f", &a, &b);
  resultado = a * b;
  printf("Resultado da multiplicação: %.2f\n", resultado);
}

int main()
{
  int opcao;

  do
  {
    printf("\nCalculadora básica com funções:\n");
    printf("Opções:\n");
    printf("1 – Soma\n");
    printf("2 – Subtração\n");
    printf("3 – Divisão\n");
    printf("4 – Multiplicação\n");
    printf("5 – Sair\n");
    printf("Escolha uma opção (1-5): ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      soma();
      break;
    case 2:
      subtracao();
      break;
    case 3:
      divisao();
      break;
    case 4:
      multiplicacao();
      break;
    case 5:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Valor inválido. Informe uma opção entre 1 e 5.\n");
      break;
    }
  } while (opcao != 5);

  return 0;
}
