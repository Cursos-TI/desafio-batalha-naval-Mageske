#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define AFETADO 5

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {AGUA};

    // --- POSICIONAMENTO DOS NAVIOS (NÍVEL AVENTUREIRO) ---
    int linhaH = 0, colunaH = 2; 
    int linhaV = 4, colunaV = 1; 
    int linhaD1 = 2, colunaD1 = 5; 
    int linhaD2 = 7, colunaD2 = 5; 

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
        tabuleiro[linhaV + i][colunaV] = NAVIO;
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
        tabuleiro[linhaD2 - i][colunaD2 + i] = NAVIO;
    }

    // --- CRIAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (5x5) ---
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    int centro = TAM_HABILIDADE / 2; // Linha/Coluna central da matriz 5x5 (índice 2)

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            
            // Regra do Cone: Expande a partir do topo central para baixo
            if (i >= centro && j >= (TAM_HABILIDADE - 1 - i) && j <= i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }

            // Regra da Cruz: Afeta apenas a linha central ou a coluna central
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }

            // Regra do Octaedro (Losango): A distância absoluta ao centro deve ser menor ou igual ao raio
            if ((i - centro >= 0 ? i - centro : centro - i) + (j - centro >= 0 ? j - centro : centro - j) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // --- APLICAÇÃO DAS HABILIDADES NO TABULEIRO ---
    // Pontos de origem (centro da habilidade) mapeados no tabuleiro principal
    int origemConeL = 2, origemConeC = 2;
    int origemCruzL = 7, origemCruzC = 2;
    int origemOctaL = 5, origemOctaC = 7;

    // Loops aninhados para sobrepor as matrizes de efeito respeitando as bordas do tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Deslocamento necessário para centralizar a matriz 5x5 na coordenada escolhida
            int deslocamento = centro;

            // Aplica Cone
            int tabLinhaCone = origemConeL + i - deslocamento;
            int tabColunaCone = origemConeC + j - deslocamento;
            if (tabLinhaCone >= 0 && tabLinhaCone < TAM_TABULEIRO && tabColunaCone >= 0 && tabColunaCone < TAM_TABULEIRO) {
                if (cone[i][j] == 1) tabuleiro[tabLinhaCone][tabColunaCone] = AFETADO;
            }

            // Aplica Cruz
            int tabLinhaCruz = origemCruzL + i - deslocamento;
            int tabColunaCruz = origemCruzC + j - deslocamento;
            if (tabLinhaCruz >= 0 && tabLinhaCruz < TAM_TABULEIRO && tabColunaCruz >= 0 && tabColunaCruz < TAM_TABULEIRO) {
                if (cruz[i][j] == 1) tabuleiro[tabLinhaCruz][tabColunaCruz] = AFETADO;
            }

            // Aplica Octaedro
            int tabLinhaOcta = origemOctaL + i - deslocamento;
            int tabColunaOcta = origemOctaC + j - deslocamento;
            if (tabLinhaOcta >= 0 && tabLinhaOcta < TAM_TABULEIRO && tabColunaOcta >= 0 && tabColunaOcta < TAM_TABULEIRO) {
                if (octaedro[i][j] == 1) tabuleiro[tabLinhaOcta][tabColunaOcta] = AFETADO;
            }
        }
    }

    // --- IMPRESSÃO DO TABULEIRO COMPLETO ---
    printf("=== TABULEIRO BATALHA NAVAL (NÍVEL MESTRE) ===\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Area Afetada\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}