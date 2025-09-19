#include <stdio.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Portuguese");

  float salarioBase, salarioFinal;
  int estadoCivil, filhos;

  printf("Digite o salário-base do colaborador: ");
  scanf("%f", &salarioBase);

  printf("Informe o estado civil (1 = Solteiro, 2 = Não solteiro): ");
  scanf("%d", &estadoCivil);

  printf("O colaborador tem filhos? (1 = Sim, 2 = Não): ");
  scanf("%d", &filhos);

  switch (estadoCivil)
  {
  case 1:
    salarioFinal = salarioBase;
    printf("Colaborador solteiro NÃO recebe bônus.\n");
    break;

  case 2:
    switch (filhos)
    {
    case 1:
      salarioFinal = salarioBase * 1.20;
      printf("Colaborador não solteiro COM filhos recebe bônus de 20%%.\n");
      printf("Colaborador não solteiro COM filhos recebe bônus de 20%%.\n");
      break;

    case 2:
      salarioFinal = salarioBase * 1.15;
      printf("Colaborador não solteiro SEM filhos recebe bônus de 15%%.\n");
      break;

    default:
      printf("Opção inválida para filhos!\n");
      return 0;
    }
    break;

  default:
    printf("Opção inválida para estado civil!\n");
    return 0;
  }

  printf("Salário final: R$ %.2f\n", salarioFinal);

  return 0;
}
