#include <stdio.h>
#include <locale.h>
#include <string.h>

/*
Faça um algoritmo que peça uma senha numérica. Em seguida, o
algoritmo deverá verificar a senha. E, enquanto a senha for diferente de
123456, o algoritmo deverá escrever a mensagem “Senha inválida, tente
novamente”, para em seguida aguardar a nova senha ser digitada. Ao fim
do algoritmo, deverá ser escrito “Senha correta. Seja bem-vindo”.
*/

int main() {
  setlocale(LC_ALL, "Portuguese");

  int senha, i;
  i = 0;

  printf("\n\t Verificar a senha!");
  printf("\n\t Informe a senha: ");
  scanf("%d", &senha);

  while (senha != 123456) {
    printf("\n\t Senha inválida, tente novamente: ");
    scanf("%d", &senha);
    i++;

    if (i == 3) {
      printf("\n\t Você execedeu o número de tentativas");
      return 0;
    }

  }

  printf("Senha correta!");


  return 0;
}
