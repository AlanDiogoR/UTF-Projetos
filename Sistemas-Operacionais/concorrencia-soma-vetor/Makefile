# =============================================================================
#  Makefile — Atividade Concorrência em S.O. (Soma de Vetor)
#  Compila o programa C++ com OpenMP e Intel TBB.
# =============================================================================

CXX        ?= g++
CXXSTD     ?= -std=c++17
OPT        ?= -O2
WARN       ?= -Wall -Wextra
OMP_FLAGS  ?= -fopenmp
TBB_FLAGS  ?= -DUSE_TBB
TBB_LIBS   ?= -ltbb

SRC        := src/somar_vetor.cpp
BIN        := somar_vetor
N_REP      ?= 30
N_VET      ?= 100000000

.PHONY: all run grafico clean help

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXSTD) $(OPT) $(WARN) $(OMP_FLAGS) $(TBB_FLAGS) $(SRC) -o $(BIN) $(TBB_LIBS)

run: $(BIN)
	./$(BIN) $(N_REP) $(N_VET)

grafico:
	python scripts/gerar_graficos.py

clean:
	rm -f $(BIN)
	rm -f resultados/*.csv resultados/*.png

help:
	@echo "Alvos disponíveis:"
	@echo "  make            -> compila o binário ($(BIN))"
	@echo "  make run        -> executa o experimento (N_REP=$(N_REP), N_VET=$(N_VET))"
	@echo "  make grafico    -> gera gráficos e estatísticas via Python"
	@echo "  make clean      -> remove binário e resultados"
