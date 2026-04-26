"""
Análise estatística e geração de gráficos para a Atividade de Concorrência em S.O.

Lê o arquivo `resultados/tempos.csv` produzido pelo programa C++ e gera:
  - resultados/estatisticas.csv     -> média, desvio padrão, mínimo e máximo.
  - resultados/grafico_sequencial.png
  - resultados/grafico_openmp.png
  - resultados/grafico_tbb.png
  - resultados/grafico_comparativo.png
  - resultados/grafico_boxplot.png

Requisitos: pandas, numpy, matplotlib (instale via `pip install -r requirements.txt`).
"""

from __future__ import annotations

import sys
from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

RAIZ = Path(__file__).resolve().parent.parent
DIR_RESULT = RAIZ / "resultados"
ARQ_CSV = DIR_RESULT / "tempos.csv"

CORES = {
    "sequencial": "#d64545",
    "openmp": "#2f80ed",
    "tbb": "#27ae60",
}

ROTULOS = {
    "sequencial": "Sequencial",
    "openmp": "OpenMP",
    "tbb": "Intel TBB",
}


def carregar_dados() -> pd.DataFrame:
    if not ARQ_CSV.exists():
        sys.exit(
            f"Arquivo {ARQ_CSV} não encontrado. Execute o programa C++ antes "
            f"(./somar_vetor) para gerar os tempos."
        )
    df = pd.read_csv(ARQ_CSV)
    esperadas = {"execucao", "sequencial", "openmp", "tbb"}
    if not esperadas.issubset(df.columns):
        sys.exit(f"CSV inválido — esperadas as colunas {esperadas}.")
    return df


def calcular_estatisticas(df: pd.DataFrame) -> pd.DataFrame:
    metodos = ["sequencial", "openmp", "tbb"]
    linhas = []
    base_media = df["sequencial"].mean()
    for m in metodos:
        col = df[m]
        media = col.mean()
        linhas.append(
            {
                "metodo": ROTULOS[m],
                "execucoes": len(col),
                "media_s": media,
                "desvio_padrao_s": col.std(ddof=1),
                "minimo_s": col.min(),
                "maximo_s": col.max(),
                "speedup_vs_sequencial": (base_media / media) if media > 0 else float("nan"),
            }
        )
    return pd.DataFrame(linhas)


def plot_individual(df: pd.DataFrame, metodo: str) -> Path:
    fig, ax = plt.subplots(figsize=(9, 4.5), dpi=120)
    tempos = df[metodo]
    media = tempos.mean()
    desvio = tempos.std(ddof=1)

    ax.plot(
        df["execucao"],
        tempos,
        marker="o",
        linewidth=1.6,
        color=CORES[metodo],
        label=ROTULOS[metodo],
    )
    ax.axhline(
        media,
        color=CORES[metodo],
        linestyle="--",
        alpha=0.6,
        label=f"Média = {media:.4f} s",
    )
    ax.fill_between(
        df["execucao"],
        media - desvio,
        media + desvio,
        color=CORES[metodo],
        alpha=0.12,
        label=f"±1 desvio ({desvio:.4f} s)",
    )

    ax.set_title(f"Tempos de execução — {ROTULOS[metodo]} (30 execuções)")
    ax.set_xlabel("Execução")
    ax.set_ylabel("Tempo (segundos)")
    ax.grid(True, linestyle=":", alpha=0.5)
    ax.legend(loc="best")
    fig.tight_layout()

    saida = DIR_RESULT / f"grafico_{metodo}.png"
    fig.savefig(saida)
    plt.close(fig)
    return saida


def plot_comparativo(df: pd.DataFrame) -> Path:
    fig, ax = plt.subplots(figsize=(10, 5), dpi=120)
    for metodo in ["sequencial", "openmp", "tbb"]:
        ax.plot(
            df["execucao"],
            df[metodo],
            marker="o",
            linewidth=1.6,
            color=CORES[metodo],
            label=ROTULOS[metodo],
        )

    ax.set_title("Comparativo dos tempos de execução — 30 execuções")
    ax.set_xlabel("Execução")
    ax.set_ylabel("Tempo (segundos)")
    ax.grid(True, linestyle=":", alpha=0.5)
    ax.legend(loc="best")
    fig.tight_layout()

    saida = DIR_RESULT / "grafico_comparativo.png"
    fig.savefig(saida)
    plt.close(fig)
    return saida


def plot_boxplot(df: pd.DataFrame) -> Path:
    fig, ax = plt.subplots(figsize=(7, 5), dpi=120)
    metodos = ["sequencial", "openmp", "tbb"]
    dados = [df[m].values for m in metodos]
    bp = ax.boxplot(
        dados,
        labels=[ROTULOS[m] for m in metodos],
        patch_artist=True,
        medianprops={"color": "black", "linewidth": 1.6},
    )
    for patch, m in zip(bp["boxes"], metodos):
        patch.set_facecolor(CORES[m])
        patch.set_alpha(0.45)

    ax.set_title("Distribuição dos tempos por abordagem")
    ax.set_ylabel("Tempo (segundos)")
    ax.grid(True, axis="y", linestyle=":", alpha=0.5)
    fig.tight_layout()

    saida = DIR_RESULT / "grafico_boxplot.png"
    fig.savefig(saida)
    plt.close(fig)
    return saida


def main() -> None:
    DIR_RESULT.mkdir(parents=True, exist_ok=True)
    df = carregar_dados()

    stats = calcular_estatisticas(df)
    arq_stats = DIR_RESULT / "estatisticas.csv"
    stats.to_csv(arq_stats, index=False, float_format="%.6f")

    print("\n=== Estatísticas (resultados/estatisticas.csv) ===")
    with pd.option_context("display.float_format", "{:.6f}".format):
        print(stats.to_string(index=False))

    artefatos = []
    for metodo in ["sequencial", "openmp", "tbb"]:
        artefatos.append(plot_individual(df, metodo))
    artefatos.append(plot_comparativo(df))
    artefatos.append(plot_boxplot(df))

    print("\nArtefatos gerados:")
    for p in [arq_stats, *artefatos]:
        print(f"  - {p.relative_to(RAIZ)}")


if __name__ == "__main__":
    main()
