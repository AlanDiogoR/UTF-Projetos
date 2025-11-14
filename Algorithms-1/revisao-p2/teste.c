#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> // Para usar 'bool'

#define TAMANHO 7
#define MINIMO 1
#define MAXIMO 20

int main()
{
  int vetor[TAMANHO];
  int i = 0; // Índice para preencher o vetor (contador de elementos únicos)
  int j;     // Índice para o loop de verificação

  // Inicializa o gerador de números pseudoaleatórios
  srand(time(NULL));

  printf("Preenchendo automaticamente o vetor de tamanho %d com números únicos entre %d e %d:\n\n",
         TAMANHO, MINIMO, MAXIMO);

  int intervalo = MAXIMO - MINIMO + 1;

  // Loop principal: continua enquanto não tivermos preenchido todas as posições
  while (i < TAMANHO)
  {
    int numero_candidato;
    bool repetido;

    // 1. Gera um novo número aleatório
    numero_candidato = (rand() % intervalo) + MINIMO;
    repetido = false;

    // 2. Verifica se o candidato já existe nas posições já preenchidas (0 até i-1)
    // Usamos 'i' como limite, pois as posições a partir de 'i' ainda não foram preenchidas.
    for (j = 0; j < i; j++)
    {
      if (vetor[j] == numero_candidato)
      {
        repetido = true;
        break; // Encontrou repetição, sai do loop de verificação
      }
    }

    // 3. Se for único, armazena e avança para a próxima posição
    if (!repetido)
    {
      vetor[i] = numero_candidato;
      printf("Posição %d preenchida: %d\n", i, vetor[i]);
      i++; // SÓ AVANÇA se o número for único
    }
    // Se estiver repetido, o 'while' recomeça, gerando um novo 'numero_candidato'
  }

  // Imprime o resultado final
  printf("\n--- Vetor Final (Único) ---\n");
  for (i = 0; i < TAMANHO; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}
