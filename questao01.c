/*
 * Nome: Alan Diogo Ribeiro de Carvalho
 * RA: 2809311
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ================================================================
   ESTRUTURAS
   ================================================================ */

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigoProprietario;
    char nome[100];
    char cpf[15];
} Proprietario;

typedef struct {
    char placa[10];
    char modelo[50];
    int ano;
} Veiculo;

typedef struct {
    int codigoProprietario;
    char placa[10];
} ProprietarioVeiculo;

typedef struct {
    Data dataDeInicio;
    Data dataDeFim;
    float quilometragemInicial;
    float quilometragemFinal;
    char veiculoUtilizado[10];
    int motorista;
} Viagem;

/* ================================================================
   VALIDAÇÕES
   ================================================================ */

static int anoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

static int diasDoMes(int mes, int ano) {
    int tabela[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes < 1 || mes > 12) return 0;
    if (mes == 2 && anoBissexto(ano)) return 29;
    return tabela[mes];
}

int validarData(Data *d) {
    if (!d) return 0;
    if (d->ano < 1) return 0;
    if (d->mes < 1 || d->mes > 12) return 0;
    if (d->dia < 1 || d->dia > diasDoMes(d->mes, d->ano)) return 0;
    return 1;
}

/* Retorna 1 se d1 <= d2, 0 caso contrario */
int compararDatas(Data *d1, Data *d2) {
    if (!d1 || !d2) return 0;
    if (d1->ano != d2->ano) return d1->ano < d2->ano;
    if (d1->mes != d2->mes) return d1->mes < d2->mes;
    return d1->dia <= d2->dia;
}

int validarQuilometragem(float inicial, float final) {
    return final > inicial;
}

/* ================================================================
   AUXILIARES INTERNOS
   ================================================================ */

static void lerData(Data *d, const char *rotulo) {
    int ok = 0;
    while (!ok) {
        printf("    %s (dd mm aaaa): ", rotulo);
        scanf("%d %d %d", &d->dia, &d->mes, &d->ano);
        if (!validarData(d))
            printf("    [ERRO] Data invalida. Tente novamente.\n");
        else
            ok = 1;
    }
}

static void imprimirData(Data *d) {
    printf("%02d/%02d/%04d", d->dia, d->mes, d->ano);
}

static int proprietarioExiste(Proprietario *props, int n, int codigo) {
    int i;
    for (i = 0; i < n; i++) {
        if ((props + i)->codigoProprietario == codigo) return 1;
    }
    return 0;
}

static int veiculoExiste(Veiculo *veics, int n, const char *placa) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp((veics + i)->placa, placa) == 0) return 1;
    }
    return 0;
}

static int contarProprietariosDoVeiculo(ProprietarioVeiculo *pv, int nPv, const char *placa) {
    int i, count = 0;
    for (i = 0; i < nPv; i++) {
        if (strcmp((pv + i)->placa, placa) == 0) count++;
    }
    return count;
}

/* ================================================================
   CADASTROS
   ================================================================ */

void cadastrarProprietarios(Proprietario *props, int n) {
    int i;
    printf("\n--- Cadastro de Proprietarios ---\n");
    for (i = 0; i < n; i++) {
        Proprietario *p = props + i;
        p->codigoProprietario = i + 1;
        printf("\nProprietario %d (codigo automatico: %d):\n", i + 1, p->codigoProprietario);
        printf("  Nome: ");
        scanf(" %99[^\n]", p->nome);
        printf("  CPF: ");
        scanf(" %14s", p->cpf);
    }
}

void cadastrarVeiculos(Veiculo *veics, int n) {
    int i;
    printf("\n--- Cadastro de Veiculos ---\n");
    for (i = 0; i < n; i++) {
        Veiculo *v = veics + i;
        printf("\nVeiculo %d:\n", i + 1);
        printf("  Placa: ");
        scanf(" %9s", v->placa);
        printf("  Modelo: ");
        scanf(" %49[^\n]", v->modelo);
        printf("  Ano: ");
        scanf("%d", &v->ano);
    }
}

void cadastrarProprietarioVeiculo(ProprietarioVeiculo *pv, int *nPv,
                                   Proprietario *props, int nProps,
                                   Veiculo *veics, int nVeics) {
    int i, j;
    printf("\n--- Associacao Proprietario-Veiculo ---\n");
    *nPv = 0;

    for (i = 0; i < nVeics; i++) {
        Veiculo *v = veics + i;
        printf("\nVeiculo: %s | %s | %d\n", v->placa, v->modelo, v->ano);

        int qtd;
        do {
            printf("  Quantos proprietarios este veiculo possui? (1 ou 2): ");
            scanf("%d", &qtd);
            if (qtd < 1 || qtd > 2)
                printf("  [ERRO] Informe 1 ou 2.\n");
        } while (qtd < 1 || qtd > 2);

        for (j = 0; j < qtd; j++) {
            int cod, valido = 0;
            while (!valido) {
                printf("  Codigo do proprietario %d: ", j + 1);
                scanf("%d", &cod);
                if (!proprietarioExiste(props, nProps, cod)) {
                    printf("  [ERRO] Codigo inexistente. Proprietarios cadastrados: 1 a %d.\n", nProps);
                } else if (contarProprietariosDoVeiculo(pv, *nPv, v->placa) >= 2) {
                    printf("  [ERRO] Este veiculo ja possui 2 proprietarios.\n");
                    valido = 1;
                } else {
                    valido = 1;
                    (pv + *nPv)->codigoProprietario = cod;
                    strcpy((pv + *nPv)->placa, v->placa);
                    (*nPv)++;
                }
            }
        }
    }
}

void cadastrarViagens(Viagem *viagens, int n,
                      Proprietario *props, int nProps,
                      Veiculo *veics, int nVeics) {
    int i;
    printf("\n--- Cadastro de Viagens ---\n");
    for (i = 0; i < n; i++) {
        Viagem *vg = viagens + i;
        printf("\nViagem %d:\n", i + 1);

        /* Datas */
        int dataOk = 0;
        while (!dataOk) {
            lerData(&vg->dataDeInicio, "Data de inicio");
            lerData(&vg->dataDeFim,    "Data de fim   ");
            if (!compararDatas(&vg->dataDeInicio, &vg->dataDeFim))
                printf("  [ERRO] Data de fim deve ser >= data de inicio.\n");
            else
                dataOk = 1;
        }

        /* Quilometragem */
        int kmOk = 0;
        while (!kmOk) {
            printf("  Quilometragem inicial (km): ");
            scanf("%f", &vg->quilometragemInicial);
            printf("  Quilometragem final   (km): ");
            scanf("%f", &vg->quilometragemFinal);
            if (!validarQuilometragem(vg->quilometragemInicial, vg->quilometragemFinal))
                printf("  [ERRO] Quilometragem final deve ser maior que a inicial.\n");
            else
                kmOk = 1;
        }

        /* Veiculo */
        int vOk = 0;
        while (!vOk) {
            printf("  Placa do veiculo utilizado: ");
            scanf(" %9s", vg->veiculoUtilizado);
            if (!veiculoExiste(veics, nVeics, vg->veiculoUtilizado))
                printf("  [ERRO] Veiculo nao encontrado.\n");
            else
                vOk = 1;
        }

        /* Motorista */
        int mOk = 0;
        while (!mOk) {
            printf("  Codigo do motorista: ");
            scanf("%d", &vg->motorista);
            if (!proprietarioExiste(props, nProps, vg->motorista))
                printf("  [ERRO] Motorista nao encontrado. Codigos validos: 1 a %d.\n", nProps);
            else
                mOk = 1;
        }
    }
}

/* ================================================================
   EXIBIÇÃO
   ================================================================ */

void exibirProprietariosComVeiculos(Proprietario *props, int nProps,
                                     Veiculo *veics, int nVeics,
                                     ProprietarioVeiculo *pv, int nPv) {
    int i, j, k;
    printf("\n======== Proprietarios e seus Veiculos ========\n");
    for (i = 0; i < nProps; i++) {
        Proprietario *p = props + i;
        printf("\n[%d] %s | CPF: %s\n", p->codigoProprietario, p->nome, p->cpf);
        printf("  Veiculos:\n");
        int algum = 0;
        for (j = 0; j < nPv; j++) {
            ProprietarioVeiculo *pvi = pv + j;
            if (pvi->codigoProprietario == p->codigoProprietario) {
                for (k = 0; k < nVeics; k++) {
                    Veiculo *v = veics + k;
                    if (strcmp(v->placa, pvi->placa) == 0) {
                        printf("    - Placa: %-10s | Modelo: %-30s | Ano: %d\n",
                               v->placa, v->modelo, v->ano);
                        algum = 1;
                        break;
                    }
                }
            }
        }
        if (!algum) printf("    (sem veiculos associados)\n");
    }
}

void exibirVeiculosComProprietario(Veiculo *veics, int nVeics,
                                    Proprietario *props, int nProps,
                                    ProprietarioVeiculo *pv, int nPv) {
    int i, j, k;
    printf("\n======== Veiculos e seus Proprietarios ========\n");
    for (i = 0; i < nVeics; i++) {
        Veiculo *v = veics + i;
        printf("\nPlaca: %-10s | Modelo: %-30s | Ano: %d\n",
               v->placa, v->modelo, v->ano);
        printf("  Proprietarios:\n");
        int algum = 0;
        for (j = 0; j < nPv; j++) {
            ProprietarioVeiculo *pvi = pv + j;
            if (strcmp(pvi->placa, v->placa) == 0) {
                for (k = 0; k < nProps; k++) {
                    Proprietario *p = props + k;
                    if (p->codigoProprietario == pvi->codigoProprietario) {
                        printf("    - [%d] %s | CPF: %s\n",
                               p->codigoProprietario, p->nome, p->cpf);
                        algum = 1;
                        break;
                    }
                }
            }
        }
        if (!algum) printf("    (sem proprietarios associados)\n");
    }
}

void exibirViagens(Viagem *viagens, int n,
                   Proprietario *props, int nProps,
                   Veiculo *veics, int nVeics) {
    int i, j;
    printf("\n======== Viagens ========\n");
    for (i = 0; i < n; i++) {
        Viagem *vg = viagens + i;
        printf("\nViagem %d:\n", i + 1);

        printf("  Data de inicio : ");
        imprimirData(&vg->dataDeInicio);
        printf("\n  Data de fim    : ");
        imprimirData(&vg->dataDeFim);

        printf("\n  Quil. inicial  : %.2f km\n", vg->quilometragemInicial);
        printf("  Quil. final    : %.2f km\n", vg->quilometragemFinal);
        printf("  Distancia      : %.2f km\n",
               vg->quilometragemFinal - vg->quilometragemInicial);

        printf("  Veiculo        : %s", vg->veiculoUtilizado);
        for (j = 0; j < nVeics; j++) {
            if (strcmp((veics + j)->placa, vg->veiculoUtilizado) == 0) {
                printf(" (%s)", (veics + j)->modelo);
                break;
            }
        }

        printf("\n  Motorista      : [%d]", vg->motorista);
        for (j = 0; j < nProps; j++) {
            if ((props + j)->codigoProprietario == vg->motorista) {
                printf(" %s", (props + j)->nome);
                break;
            }
        }
        printf("\n");
    }
}

/* ================================================================
   MAIN
   ================================================================ */

int main(void) {
    int nProps, nVeics, nViagens;

    printf("========================================================\n");
    printf("  Sistema de Gestao: Proprietarios, Veiculos e Viagens  \n");
    printf("========================================================\n\n");

    printf("Quantidade de proprietarios: ");
    scanf("%d", &nProps);
    if (nProps < 1) { printf("[ERRO] Informe ao menos 1 proprietario.\n"); return 1; }

    printf("Quantidade de veiculos     : ");
    scanf("%d", &nVeics);
    if (nVeics < 1) { printf("[ERRO] Informe ao menos 1 veiculo.\n"); return 1; }

    printf("Quantidade de viagens      : ");
    scanf("%d", &nViagens);
    if (nViagens < 1) { printf("[ERRO] Informe ao menos 1 viagem.\n"); return 1; }

    /* Alocacao dinamica */
    Proprietario     *props   = (Proprietario *)    calloc(nProps,       sizeof(Proprietario));
    Veiculo          *veics   = (Veiculo *)          calloc(nVeics,       sizeof(Veiculo));
    ProprietarioVeiculo *pv   = (ProprietarioVeiculo *)calloc(nVeics * 2, sizeof(ProprietarioVeiculo));
    Viagem           *viagens = (Viagem *)           calloc(nViagens,     sizeof(Viagem));

    if (!props || !veics || !pv || !viagens) {
        printf("[ERRO] Falha na alocacao de memoria.\n");
        free(props); free(veics); free(pv); free(viagens);
        return 1;
    }

    /* Preenchimento */
    cadastrarVeiculos(veics, nVeics);
    cadastrarProprietarios(props, nProps);

    int nPv = 0;
    cadastrarProprietarioVeiculo(pv, &nPv, props, nProps, veics, nVeics);

    cadastrarViagens(viagens, nViagens, props, nProps, veics, nVeics);

    /* Exibicao */
    exibirProprietariosComVeiculos(props, nProps, veics, nVeics, pv, nPv);
    exibirVeiculosComProprietario(veics, nVeics, props, nProps, pv, nPv);
    exibirViagens(viagens, nViagens, props, nProps, veics, nVeics);

    /* Liberacao de memoria */
    free(props);
    free(veics);
    free(pv);
    free(viagens);

    printf("\n[INFO] Memoria liberada. Programa encerrado.\n");
    return 0;
}
