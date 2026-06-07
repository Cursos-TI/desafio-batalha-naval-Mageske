#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {AGUA};

    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    int linhaH = 2, colunaH = 3;
    int linhaV = 5, colunaV = 6;

    bool posicionamentoValido = true;

    if (colunaH + TAM_NAVIO > TAM_TABULEIRO || linhaH >= TAM_TABULEIRO) {
        posicionamentoValido = false;
    }
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO || colunaV >= TAM_TABULEIRO) {
        posicionamentoValido = false;
    }

    if (posicionamentoValido) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (linhaV + i == linhaH && colunaV >= colunaH && colunaV < colunaH + TAM_NAVIO) {
                posicionamentoValido = false;
            }
        }
    }

    if (!posicionamentoValido) {
        printf("Erro: Posições dos navios inválidas ou há sobreposição!\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}