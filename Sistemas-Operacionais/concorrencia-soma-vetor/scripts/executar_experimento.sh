#!/usr/bin/env bash
# =============================================================================
#  Script de execução do experimento (Linux / WSL / macOS)
#  - Compila o binário com OpenMP + TBB.
#  - Executa o programa, que internamente roda 30 repetições por abordagem.
#  - Em seguida chama o script Python para gerar gráficos e estatísticas.
# =============================================================================

set -euo pipefail

DIR_SCRIPT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DIR_RAIZ="$(cd "$DIR_SCRIPT/.." && pwd)"
cd "$DIR_RAIZ"

N_REP="${1:-30}"
N_VET="${2:-100000000}"

echo "============================================================"
echo "  Compilando somar_vetor.cpp"
echo "============================================================"
g++ -O2 -std=c++17 -Wall -Wextra -fopenmp -DUSE_TBB \
    src/somar_vetor.cpp -o somar_vetor -ltbb

echo
echo "============================================================"
echo "  Executando experimento  (rep=$N_REP, vetor=$N_VET)"
echo "============================================================"
time ./somar_vetor "$N_REP" "$N_VET"

echo
echo "============================================================"
echo "  Gerando gráficos e estatísticas"
echo "============================================================"
if command -v python3 >/dev/null 2>&1; then
    python3 scripts/gerar_graficos.py
elif command -v python >/dev/null 2>&1; then
    python scripts/gerar_graficos.py
else
    echo "Python não encontrado — pule esta etapa ou instale Python 3."
fi

echo
echo "Concluído. Veja os artefatos em ./resultados/"
