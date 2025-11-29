/*
Elabore um programa com a definição de um registro para funcionário com os campos nome, cargo e salário. Leia os dados para 10 funcionários e apresente o valor do menor salário.
*/

#include <stdio.h>
#include <string.h>
#define maxFuncionarios 10
#define maxNome 50
#define maxCargo 30

struct funcionarioProps {
  char nome[maxNome];
  char cargo[maxCargo];
  float salario;
};

int main() {
  struct funcionarioProps funcionarios[maxFuncionarios];
  float menorSalario;

  for (int i = 0; i < maxFuncionarios; i++) {
    printf("Cadastro do funcionario %d:\n", i + 1);
    printf("Nome: ");
    fgets(funcionarios[i].nome, maxNome, stdin);
    printf("Cargo: ");
    fgets(funcionarios[i].cargo, maxCargo, stdin);
    printf("Salario: ");
    scanf("%f", &funcionarios[i].salario);
    getchar(); 
    printf("\n");
  }

  menorSalario = funcionarios[0].salario;
  for (int i = 1; i < maxFuncionarios; i++) {
    if (funcionarios[i].salario < menorSalario) {
      menorSalario = funcionarios[i].salario;
    }
  }

  printf("O menor salario entre os funcionarios cadastrados e: %.2f\n", menorSalario);

  return 0;
}


