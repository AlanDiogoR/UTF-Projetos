/*
Faça um algoritmo de jogo da velha! */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 3

void inicializaTabuleiro(char tabuleiro[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      tabuleiro[i][j] = ' ';
    }
  }
}

void exibeTabuleiro(char tabuleiro[TAM][TAM])
{
  printf("\n");
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      printf(" %c ", tabuleiro[i][j]);
      if (j < TAM - 1)
        printf("|");
    }
    printf("\n");
    if (i < TAM - 1)
    {
      for (int k = 0; k < TAM; k++)
      {
        printf("---");
        if (k < TAM - 1)
          printf("+");
      }
      printf("\n");
    }
  }
  printf("\n");
}

bool verificaVencedor(char tabuleiro[TAM][TAM], char jogador)
{
  for (int i = 0; i < TAM; i++)
  {
    if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
        (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador))
    {
      return true;
    }
  }
  if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
      (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
  {
    return true;
  }
  return false;
}

bool verificaEmpate(char tabuleiro[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      if (tabuleiro[i][j] == ' ')
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  char tabuleiro[TAM][TAM];
  char jogadorAtual = 'X';
  bool jogoAtivo = true;

  inicializaTabuleiro(tabuleiro);

  while (jogoAtivo)
  {
    exibeTabuleiro(tabuleiro);
    int linha, coluna;
    printf("Jogador %c, insira sua jogada (linha e coluna): ", jogadorAtual);
    scanf("%d %d", &linha, &coluna);

    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM || tabuleiro[linha][coluna] != ' ')
    {
      printf("Jogada inválida! Tente novamente.\n");
      continue;
    }

    tabuleiro[linha][coluna] = jogadorAtual;

    if (verificaVencedor(tabuleiro, jogadorAtual))
    {
      exibeTabuleiro(tabuleiro);
      printf("Jogador %c venceu!\n", jogadorAtual);
      jogoAtivo = false;
    }
    else if (verificaEmpate(tabuleiro))
    {
      exibeTabuleiro(tabuleiro);
      printf("Empate!\n");
      jogoAtivo = false;
    }
    else
    {
      jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }
  }

  return 0;
}
