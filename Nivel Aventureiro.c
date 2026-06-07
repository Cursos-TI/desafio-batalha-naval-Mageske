#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Cria o tabuleiro preenchido com Água (0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {AGUA};

    // Coordenadas iniciais de cada tipo de navio
    int linhaH = 0, colunaH = 2;   // Navio Horizontal
    int linhaV = 4, colunaV = 1;   // Navio Vertical
    int linhaD1 = 2, colunaD1 = 5; // Navio Diagonal (Aumenta linha e coluna)
    int linhaD2 = 7, colunaD2 = 5; // Navio Diagonal (Diminui linha e aumenta coluna)

    bool valido = true;

    // Validações para garantir que nenhum navio saia do tabuleiro
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO || linhaH >= TAM_TABULEIRO) valido = false;
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO || colunaV >= TAM_TABULEIRO) valido = false;
    if (linhaD1 + TAM_NAVIO > TAM_TABULEIRO || colunaD1 + TAM_NAVIO > TAM_TABULEIRO) valido = false;
    if (linhaD2 - TAM_NAVIO < -1 || colunaD2 + TAM_NAVIO > TAM_TABULEIRO) valido = false;

    // Posiciona os navios alterando o valor da água (0) para Navio (3)
    if (valido) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) valido = false;
            tabuleiro[linhaH][colunaH + i] = NAVIO;

            if (tabuleiro[linhaV + i][colunaV] != AGUA) valido = false;
            tabuleiro[linhaV + i][colunaV] = NAVIO;

            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) valido = false;
            tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;

            if (tabuleiro[linhaD2 - i][colunaD2 + i] != AGUA) valido = false;
            tabuleiro[linhaD2 - i][colunaD2 + i] = NAVIO;
        }
    }

    if (!valido) {
        printf("Erro: Posicionamento invalido ou houve sobreposicao de navios!\n");
        return 1;
    }

    // Exibe o resultado final na tela
    printf("=== TABULEIRO BATALHA NAVAL (AVENTUREIRO) ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}