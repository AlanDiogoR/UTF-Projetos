#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
  double massa_ton, aceleracao_ms2, tempo_s;
  double massa_kg, velocidade_ms, velocidade_kmh, comprimento_pista, trabalho_mecanico;

  printf("Digite a massa do avião (toneladas): ");
  scanf("%lf", &massa_ton);
  printf("Digite a aceleração do avião (m/s^2): ");
  scanf("%lf", &aceleracao_ms2);
  printf("Digite o tempo até a decolagem (segundos): ");
  scanf("%lf", &tempo_s);

  massa_kg = massa_ton * 1000; // Converter toneladas para kg

  velocidade_ms = aceleracao_ms2 * tempo_s; // v = a * t
  velocidade_kmh = velocidade_ms * 3.6;     // Converter m/s para km/h

  comprimento_pista = 0.5 * aceleracao_ms2 * pow(tempo_s, 2); // S = 0.5 * a * t^2

  trabalho_mecanico = (massa_kg * pow(velocidade_ms, 2)) / 2; // W = (m * v^2) / 2

  printf("\nVelocidade atingida na decolagem: %.2lf km/h\n", velocidade_kmh);
  printf("Comprimento da pista necessário: %.2lf m\n", comprimento_pista);
  printf("Trabalho mecânico realizado: %.2lf J\n", trabalho_mecanico);

  return 0;
}
