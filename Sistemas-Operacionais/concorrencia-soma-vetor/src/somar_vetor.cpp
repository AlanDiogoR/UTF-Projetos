// =============================================================================
//  Atividade: Concorrência em Sistemas Operacionais
//  Soma dos elementos de um vetor de 10^8 elementos em três abordagens:
//    1. Sequencial (loop for tradicional)
//    2. Paralela com OpenMP (#pragma omp parallel for reduction)
//    3. Paralela com Intel TBB (parallel_reduce)
//
//  O programa executa cada abordagem N_REPETICOES vezes (padrão: 30) e grava
//  os tempos em um CSV (resultados/tempos.csv) para posterior análise.
//
//  Compilação:
//      g++ -O2 -std=c++17 -fopenmp src/somar_vetor.cpp -o somar_vetor -ltbb
//
//  Execução:
//      ./somar_vetor [n_repeticoes] [tamanho_vetor]
//
//  Autor: Alan Diogo R. — UTFPR / Engenharia de Software
// =============================================================================

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#ifdef _OPENMP
#include <omp.h>
#endif

#ifdef USE_TBB
#include <tbb/blocked_range.h>
#include <tbb/global_control.h>
#include <tbb/parallel_reduce.h>
#endif

namespace fs = std::filesystem;
using Clock = std::chrono::high_resolution_clock;

// ---------- Implementações da soma --------------------------------------------

static long long somaSequencial(const std::vector<int>& v) {
    long long soma = 0;
    for (std::size_t i = 0; i < v.size(); ++i) {
        soma += v[i];
    }
    return soma;
}

#ifdef _OPENMP
static long long somaOpenMP(const std::vector<int>& v) {
    long long soma = 0;
    const std::int64_t n = static_cast<std::int64_t>(v.size());
    #pragma omp parallel for reduction(+ : soma) schedule(static)
    for (std::int64_t i = 0; i < n; ++i) {
        soma += v[i];
    }
    return soma;
}
#endif

#ifdef USE_TBB
static long long somaTBB(const std::vector<int>& v) {
    return tbb::parallel_reduce(
        tbb::blocked_range<std::size_t>(0, v.size()),
        0LL,
        [&v](const tbb::blocked_range<std::size_t>& r, long long acc) {
            for (std::size_t i = r.begin(); i != r.end(); ++i) {
                acc += v[i];
            }
            return acc;
        },
        std::plus<long long>());
}
#endif

// ---------- Utilitários -------------------------------------------------------

template <typename Func>
static double medirTempo(Func&& f, long long& somaSaida) {
    auto inicio = Clock::now();
    somaSaida = f();
    auto fim = Clock::now();
    std::chrono::duration<double> dur = fim - inicio;
    return dur.count();
}

static void imprimirCabecalho(const std::string& titulo) {
    std::cout << "\n";
    std::cout << "============================================================\n";
    std::cout << "  " << titulo << "\n";
    std::cout << "============================================================\n";
}

// ---------- Programa principal ------------------------------------------------

int main(int argc, char* argv[]) {
    int nRepeticoes = (argc >= 2) ? std::atoi(argv[1]) : 30;
    std::size_t N  = (argc >= 3) ? static_cast<std::size_t>(std::atoll(argv[2]))
                                 : 100'000'000ULL; // 10^8

    if (nRepeticoes <= 0) nRepeticoes = 30;
    if (N == 0)            N = 100'000'000ULL;

    imprimirCabecalho("Atividade — Concorrência em S.O. (Soma de Vetor)");
    std::cout << "Tamanho do vetor : " << N << " elementos\n";
    std::cout << "Repetições       : " << nRepeticoes << " por abordagem\n";
#ifdef _OPENMP
    std::cout << "OpenMP threads   : " << omp_get_max_threads() << "\n";
#else
    std::cout << "OpenMP           : NÃO compilado (defina -fopenmp)\n";
#endif
#ifdef USE_TBB
    std::cout << "TBB              : habilitado\n";
#else
    std::cout << "TBB              : NÃO compilado (defina -DUSE_TBB e -ltbb)\n";
#endif

    // ---- Geração do vetor ----------------------------------------------------
    imprimirCabecalho("Gerando vetor de teste");
    std::vector<int> vetor(N);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 100);
    for (std::size_t i = 0; i < N; ++i) vetor[i] = dist(rng);
    std::cout << "Vetor gerado com sucesso.\n";

    // ---- Estrutura de resultados --------------------------------------------
    std::vector<double> tSeq(nRepeticoes, 0.0);
    std::vector<double> tOmp(nRepeticoes, 0.0);
    std::vector<double> tTbb(nRepeticoes, 0.0);

    long long somaRef = 0;
    {
        long long s;
        medirTempo([&] { return somaSequencial(vetor); }, s);
        somaRef = s;
    }

    // ---- Sequencial ---------------------------------------------------------
    imprimirCabecalho("Executando: SEQUENCIAL");
    for (int i = 0; i < nRepeticoes; ++i) {
        long long s;
        tSeq[i] = medirTempo([&] { return somaSequencial(vetor); }, s);
        std::cout << "  [Seq] exec " << std::setw(2) << (i + 1) << "/"
                  << nRepeticoes << " -> " << std::fixed
                  << std::setprecision(6) << tSeq[i] << " s"
                  << (s == somaRef ? "" : "  [DIVERGENTE!]") << "\n";
    }

#ifdef _OPENMP
    imprimirCabecalho("Executando: OpenMP");
    for (int i = 0; i < nRepeticoes; ++i) {
        long long s;
        tOmp[i] = medirTempo([&] { return somaOpenMP(vetor); }, s);
        std::cout << "  [Omp] exec " << std::setw(2) << (i + 1) << "/"
                  << nRepeticoes << " -> " << std::fixed
                  << std::setprecision(6) << tOmp[i] << " s"
                  << (s == somaRef ? "" : "  [DIVERGENTE!]") << "\n";
    }
#endif

#ifdef USE_TBB
    imprimirCabecalho("Executando: TBB");
    for (int i = 0; i < nRepeticoes; ++i) {
        long long s;
        tTbb[i] = medirTempo([&] { return somaTBB(vetor); }, s);
        std::cout << "  [Tbb] exec " << std::setw(2) << (i + 1) << "/"
                  << nRepeticoes << " -> " << std::fixed
                  << std::setprecision(6) << tTbb[i] << " s"
                  << (s == somaRef ? "" : "  [DIVERGENTE!]") << "\n";
    }
#endif

    // ---- Salvar CSV ---------------------------------------------------------
    fs::path saidaDir = "resultados";
    std::error_code ec;
    fs::create_directories(saidaDir, ec);
    fs::path csvPath = saidaDir / "tempos.csv";

    std::ofstream csv(csvPath);
    if (!csv) {
        std::cerr << "Erro: não foi possível abrir " << csvPath << "\n";
        return 1;
    }
    csv << "execucao,sequencial,openmp,tbb\n";
    csv << std::fixed << std::setprecision(9);
    for (int i = 0; i < nRepeticoes; ++i) {
        csv << (i + 1) << "," << tSeq[i] << "," << tOmp[i] << "," << tTbb[i]
            << "\n";
    }
    csv.close();

    imprimirCabecalho("Resumo");
    std::cout << "Soma de referência : " << somaRef << "\n";
    std::cout << "CSV salvo em       : " << csvPath.string() << "\n";
    std::cout << "Para gerar gráficos e estatísticas execute:\n";
    std::cout << "    python scripts/gerar_graficos.py\n\n";
    return 0;
}
