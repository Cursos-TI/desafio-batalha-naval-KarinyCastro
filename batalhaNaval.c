#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // Desafio Batalha Naval - MateCheck
    // Nível Novato - Posicionamento dos Navios
    // Declaração do tabuleiro e inicialização com água (0)
    
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais para os navios
    // Navio Horizontal
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    // Navio Vertical
    int linha_vertical = 5;
    int coluna_vertical = 7;

    int pode_colocar = 1; // Flag para checar se posição é válida

    // Validação do navio horizontal
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != VALOR_AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada no navio horizontal.\n");
        }
    } else {
        printf("Erro: navio horizontal não cabe no tabuleiro.\n");
    }

    // Reinicia flag
    pode_colocar = 1;

    // Validação do navio vertical
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != VALOR_AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: sobreposição detectada no navio vertical.\n");
        }
    } else {
        printf("Erro: navio vertical não cabe no tabuleiro.\n");
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

