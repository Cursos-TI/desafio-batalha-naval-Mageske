#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Inicializa o tabuleiro 10x10 com 0 (Água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {AGUA};

    // Vetores unidimensionais representando os navios 
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais 
    int linhaH = 2, colunaH = 3; // Navio Horizontal começará em (2,3)
    int linhaV = 5, colunaV = 6; // Navio Vertical começará em (5,6)

    // Variável de controle para validação
    bool posicionamentoValido = true;

    // --- VALIDAÇÃO 1: Limites do Tabuleiro ---
    // Verifica se o navio horizontal ultrapassa a borda direita
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO || linhaH >= TAM_TABULEIRO) {
        posicionamentoValido = false;
    }
    // Verifica se o navio vertical ultrapassa a borda inferior
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO || colunaV >= TAM_TABULEIRO) {
        posicionamentoValido = false;
    }

    // --- VALIDAÇÃO 2: Sobreposição ---
    // Se passou na primeira validação, checa se os navios vão se colidir
    if (posicionamentoValido) {
        // Verifica se o navio vertical vai cruzar o espaço do horizontal
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (linhaV + i == linhaH && colunaV >= colunaH && colunaV < colunaH + TAM_NAVIO) {
                posicionamentoValido = false;
            }
        }
    }

    // --- POSICIONAMENTO E IMPRESSÃO ---
    if (!posicionamentoValido) {
        printf("Erro: Posições dos navios inválidas ou há sobreposição!\n");
        return 1; // Encerra o programa com erro
    }

    // Copiando os dados dos vetores para a matriz do tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i]; // Preenche horizontalmente
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];   // Preenche verticalmente
    }

    // Exibição do tabuleiro usando loops aninhados
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    return 0;
}