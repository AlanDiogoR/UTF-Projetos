#include <stdio.h>
#include <string.h>

/*
01) Elabore um programa em Linguagem C para coletar o código (cadeia com 4
caracteres, Ex: P001), o preço (em reais) e a quantidade(inteiro) de cada produto em
estoque. O programa deve:
- Para cada cadastro, exibir:
a) Preço do produto com código par;
b) Código do produto com preço maior ou igual a R$ 110,00.
- Ao final da execução do programa, exibir:
c) Quantidade de produtos distintos disponíveis em estoque;
d) Percentual de produtos com preço entre R$ 150,00 e R$ 500,00;
e) Preço do produto com código de identificação P101;
f) Código do produto mais barato.
Durante a execução, após cada coleta, o programa deve perguntar ao usuário: Deseja
cadastrar mais produtos (Sim ou sim)?
 Obrigatório:
- Estrutura de repetição com teste no início (while);
- Operadores lógicos;
- Operador de resto;
- Comando de comparação de string;
*/

int main()
{
  char codigo[5];
  float preco, preco_mais_barato = 1000000.0, preco_p101 = -1.0;
  int quantidade, count_distintos = 0, count_150_500 = 0;
  char continuar;

  do
  {
    printf("Digite o codigo do produto (4 caracteres): ");
    scanf("%s", codigo);
    printf("Digite o preco do produto (em reais): ");
    scanf("%f", &preco);
    printf("Digite a quantidade do produto (inteiro): ");
    scanf("%d", &quantidade);

    count_distintos++;

    if (preco >= 150.0 && preco <= 500.0)
    {
      count_150_500++;
    }

    if (codigo[3] % 2 == 0) // Verifica se o ultimo caractere do codigo e par
    {
      printf("Preco do produto com codigo par: R$ %.2f\n", preco);
    }

    if (preco >= 110.0)
    {
      printf("Codigo do produto com preco maior ou igual a R$ 110,00: %s\n", codigo);
    }

    if (strcmp(codigo, "P101") == 0)
    {
      preco_p101 = preco;
    }

    if (preco < preco_mais_barato)
    {
      preco_mais_barato = preco;
    }

    printf("Deseja cadastrar mais produtos (S/s para sim)? ");
    scanf(" %c", &continuar);

  } while (continuar == 'S' || continuar == 's');

  printf("Quantidade de produtos distintos em estoque: %d\n", count_distintos);
  if (count_distintos > 0)
  {
    float percentual_150_500 = ((float)count_150_500 / count_distintos) * 100.0;
    printf("Percentual de produtos com preco entre R$ 150,00 e R$ 500,00: %.2f%%\n", percentual_150_500);
  }
  else
  {
    printf("Percentual de produtos com preco entre R$ 150,00 e R$ 500,00: N/A\n");
  }

  if (preco_p101 != -1.0)
  {
    printf("Preco do produto com codigo P101: R$ %.2f\n", preco_p101);
  }
  else
  {
    printf("Produto com codigo P101 nao cadastrado.\n");
  }

  printf("Preco do produto mais barato: R$ %.2f\n", preco_mais_barato);

  return 0;
}
