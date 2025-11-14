#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15

int main()
{
  srand(time(NULL));
  int i;
  // Inicializa preco e soma
  float preco[TAM];
  float soma = 0.0; // CORREÇÃO 1: Inicializar soma

  // 1. Gerar preços e calcular a soma original
  for (i = 0; i < TAM; i++)
  {
    // Gera valores inteiros e armazena em float (para fins de teste)
    // Para preços reais, talvez devesse gerar float diretamente.
    preco[i] = (float)(rand() % 10000) / 100.0; // Gera valor entre 0.00 e 99.99
    soma = soma + preco[i];
  }

  // a) Apresente o vetor original
  printf("\n--- Item (a): Vetor Original ---\n");
  for (i = 0; i < TAM; i++)
  {
    printf("|%7.2f| ", preco[i]); // Usando .2f para formato de preço
    if ((i + 1) % 5 == 0)
    { // Quebra de linha a cada 5 elementos para melhor visualização
      printf("\n");
    }
  }

  // b) Apresente o saldo em dinheiro do estoque de produtos (SOMA)
  printf("\n\n--- Item (b): Soma Total do Estoque ---\n");
  // Usando %.2f para mostrar duas casas decimais para a soma
  printf("\tSoma total: R$ %.2f\n", soma);

  // c) Modifique o vetor de modo que os valores que estão nas POSIÇÕES PARES
  // (índices 0, 2, 4, ...) tenham um aumento de 5%
  printf("\n--- Item (c): Vetor Após Aumento de 5%% nas Posições Pares ---\n");
  for (i = 0; i < TAM; i++)
  {
    // Verifica se o ÍNDICE (i) é par
    if (i % 2 == 0)
    {
      preco[i] = preco[i] * 1.05; // Aumento de 5%
    }
    // Apresenta o vetor modificado imediatamente
    printf("|%7.2f| ", preco[i]);
    if ((i + 1) % 5 == 0)
    {
      printf("\n");
    }
  }

  // d) Apresente o vetor resultante em ordem inversa
  printf("\n\n--- Item (d): Vetor Resultante em Ordem Inversa ---\n");
  // Começa no último índice (TAM - 1) e vai até 0
  for (i = TAM - 1; i >= 0; i--)
  {
    printf("|%7.2f| ", preco[i]);
    // Ajuste a quebra de linha para a ordem inversa, se desejar
    if ((TAM - 1 - i + 1) % 5 == 0)
    {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}
