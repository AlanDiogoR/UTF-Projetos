# =============================================================================
#  Script de execução do experimento (Windows / PowerShell)
#  Requisitos: g++ (MSYS2/MinGW) com suporte a OpenMP e biblioteca TBB instalada.
#  Uso:
#     powershell -ExecutionPolicy Bypass -File scripts\executar_experimento.ps1 [n_rep] [tam_vetor]
# =============================================================================

param(
    [int]$NRep = 30,
    [long]$NVet = 100000000
)

$ErrorActionPreference = "Stop"

$RaizProjeto = Split-Path -Parent $PSScriptRoot
Set-Location $RaizProjeto

Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "  Compilando somar_vetor.cpp" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan

$compilerArgs = @(
    "-O2", "-std=c++17", "-Wall", "-Wextra",
    "-fopenmp", "-DUSE_TBB",
    "src/somar_vetor.cpp",
    "-o", "somar_vetor.exe",
    "-ltbb"
)

& g++ @compilerArgs
if ($LASTEXITCODE -ne 0) {
    Write-Host "Falha na compilação. Verifique se o g++ e a TBB estão instalados." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "  Executando experimento (rep=$NRep, vetor=$NVet)" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan

$cron = [System.Diagnostics.Stopwatch]::StartNew()
& ".\somar_vetor.exe" $NRep $NVet
$cron.Stop()
Write-Host ("Tempo total (wall clock): {0:N3} s" -f $cron.Elapsed.TotalSeconds) -ForegroundColor Yellow

Write-Host ""
Write-Host "============================================================" -ForegroundColor Cyan
Write-Host "  Gerando gráficos e estatísticas" -ForegroundColor Cyan
Write-Host "============================================================" -ForegroundColor Cyan

$python = Get-Command python -ErrorAction SilentlyContinue
if ($null -eq $python) { $python = Get-Command python3 -ErrorAction SilentlyContinue }
if ($null -eq $python) {
    Write-Host "Python não encontrado — instale Python 3 ou pule esta etapa." -ForegroundColor Yellow
} else {
    & $python.Source "scripts/gerar_graficos.py"
}

Write-Host ""
Write-Host "Concluído. Veja os artefatos em .\resultados\" -ForegroundColor Green
