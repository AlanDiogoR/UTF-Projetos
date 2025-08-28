#include <stdio.h> 
#include <math.h>
int main() {

  int opcao;
  char continuar;

  continuar =  's';

  do {

    printf("\n *****  Lista de Exercicios  ***** \n");
    printf("\n Ao final do programa informar apenas s para continuar \n");
    printf("\nEscolha uma opcao de 1 a 9: ");
    scanf("%d", &opcao);

    switch (opcao){
      case 1: {
        //média notas
        float n1,n2,n3,n4,media;

        printf("Informe a primeira nota: ");
        scanf("%f", &n1);
        printf("Informe a segunda nota: ");
        scanf("%f", &n2);
        printf("Informe a terceira nota: ");
        scanf("%f", &n3);
        printf("Informe a quarta nota: ");
        scanf("%f", &n4);

        media = (n1+n2+n3+n4)/4;

        printf("A média do aluno é: %.2f \n", media);

        break;
      } 

      case 2: {
        //02 area circunferencia
        float raio, area;

        printf("Informe o raio da circunferencia: ");
        scanf("%f", &raio);

        area = M_PI * raio * raio;

        printf("A area da circunferencia e: %.2f\n", area);

        break;
      }

      case 3: {
        //03 tanque 

        float raio, altura, preco, lata, litros, latas, custos, area; 

        printf("Informe o raio do tanque em (m): ");
        scanf("%f", &raio);
        printf("Informe a altura do tanque em (m): ");
        scanf("%f", &altura);
        printf("Informe o preço da lata de tintas em (R$): ");
        scanf("%f", &preco);

        area = 2 * M_PI * raio * (raio * altura);
        litros = area /  3.0;
        latas = litros / 5.0;
        custos = latas * preco;

        printf("A area do tanque e: %2.f\n", area);
        printf("Litros de tinatas necessario: %.2f\n", litros);
        printf("Numero de latas necessarisas: %.2f\n", latas);
        printf("O custo total e: %.2f\n", custos);

        break;

      }

      case 4: {
        //sal final 
        float horasTrab, horasExtra, horasFalta, salMin, valHora, bruto, inss, salFinal;

        printf("Informe as horas trabalhadas: ");
        scanf("%f", &horasTrab);
        printf("Informe as horas extras: ");
        scanf("%f", &horasExtra);
        printf("Informe as horas ausentes: ");
        scanf("%f", &horasFalta);
        printf("Informe o salrio minimo: ");
        scanf("%f", &salMin);

        valHora = salMin * 0.04;
        bruto = (horasTrab * valHora) + (horasExtra * (valHora * 1.5)) - (horasFalta * valHora);
        inss = bruto * 0.11;
        salFinal = bruto - inss;

        printf("Salario Final: R$%.2f", salFinal);

        break;
      }

      case 5: {
        // 05 salario familia 

        float salario, salFamilia;
        int dependentes;

        printf("Informe o salario R$: ");
        scanf("%f", &salario);
        printf("Informe o numero de dependetes: ");
        scanf("%d", &dependentes);

        salFamilia = salario * 0.02 * dependentes;

        printf("Salario familia: R$: %.2f", salFamilia);

        break;
        
      }

      case 6: {
        //06 p vendas
        float precoMonatadora, lucro, ipi, icm, precoFinal, impostos;

        printf("Informe o preco da montadora R$: ");
        scanf("%f", &precoMonatadora);

        lucro = precoMonatadora * 0.15;
        ipi = precoMonatadora * 0.11;
        icm = precoMonatadora * 0.17;
        impostos = ipi + icm;
        precoFinal = precoMonatadora + lucro + impostos;

        printf("Preco final do carro: R$%.2f\n", precoFinal);
        printf("Valor dos impostos IPI + ICM: R$%.2f\n", impostos);

        break;

      }

      case 7: { 
        //07glao comb

        float tempo, velocidade, distancia, litros, galoesReais;
        int galoesCheios;

        printf("INforme o tempo de viagem em horas: ");
        scanf("%f", &tempo);
        printf("Informe a velocidade media km/h: ");
        scanf("%f", &velocidade);

        distancia = tempo * velocidade;
        litros = distancia / 12.0;
        galoesReais = litros / 5.0;
        galoesCheios = ceil(galoesReais);

        printf("Distancia percorrida: %.2f\n", distancia);
        printf("Combustivel necessario: %.2f\n", litros);
        printf("Galoes de 5l valor real: %.2f\n", galoesReais);
        printf("Galoes  de 5l  necessarios cheios: %d\n", galoesCheios);

        break;

      }

      case 8: { 
        //08   distancia pontos 

        float x1, x2, y1, y2, distancia;

        printf("Informe X1: ");
        scanf("%f", &x1);
        printf("Informe Y1: ");
        scanf("%f", &y1);
        printf("Informe X2: ");
        scanf("%f", &x2);
        printf("Informe Y2: ");
        scanf("%f", &y2);

        distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        printf("Distancia entre dois pontos: %.2f",distancia);

        break;

      }

      case 9: {
        // 09 alunos

        int alunos, grupos, resto;

        printf("Informe a quantidade de alunos: ");
        scanf("%d", &alunos);

        grupos = alunos / 4;
        resto  = alunos % 4;

        printf("Quantidade de grupos de 4: %d\n", grupos);
        printf("Alunos sem grupo: %d\n", resto);

        break;
      }

      default:
        printf("Questão invalida!\n");
    }

    printf("\nGostaria de ver outra questao? (s/n): ");
    scanf(" %c", &continuar);

  } while(continuar == 's' || continuar == 'S');

  printf("\nPrograma encerrado.\n");
  return 0;

}