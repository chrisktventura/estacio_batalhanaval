#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Usando %2d para alinhar as colunas
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                return 0; // Retorna 0 se a posição já estiver ocupada
            }
            tabuleiro[linha][coluna + i] = 3; // Marca a posição do navio
        }
        return 1; // Retorna 1 se o navio foi posicionado com sucesso
    }
    return 0; // Retorna 0 se o navio não couber no tabuleiro
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                return 0; // Retorna 0 se a posição já estiver ocupada
            }
            tabuleiro[linha + i][coluna] = 3; // Marca a posição do navio
        }
        return 1; // Retorna 1 se o navio foi posicionado com sucesso
    }
    return 0; // Retorna 0 se o navio não couber no tabuleiro
}

// Função para posicionar um navio na diagonal (crescente)
int posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) {
                return 0; // Retorna 0 se a posição já estiver ocupada
            }
            tabuleiro[linha + i][coluna + i] = 3; // Marca a posição do navio
        }
        return 1; // Retorna 1 se o navio foi posicionado com sucesso
    }
    return 0; // Retorna 0 se o navio não couber no tabuleiro
}

// Função para posicionar um navio na diagonal (decrescente)
int posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna - TAMANHO_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) {
                return 0; // Retorna 0 se a posição já estiver ocupada
            }
            tabuleiro[linha + i][coluna - i] = 3; // Marca a posição do navio
        }
        return 1; // Retorna 1 se o navio foi posicionado com sucesso
    }
    return 0; // Retorna 0 se o navio não couber no tabuleiro
}

int main() {
    // Inicializando o tabuleiro com 0s (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionando os navios no tabuleiro
    // Navios horizontais e verticais
    if (!posicionarNavioHorizontal(tabuleiro, 2, 3)) {
        printf("Falha ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, 5, 6)) {
        printf("Falha ao posicionar navio vertical!\n");
    }

    // Navios diagonais
    if (!posicionarNavioDiagonalCrescente(tabuleiro, 0, 0)) {
        printf("Falha ao posicionar navio diagonal crescente!\n");
    }
    if (!posicionarNavioDiagonalDecrescente(tabuleiro, 9, 9)) {
        printf("Falha ao posicionar navio diagonal decrescente!\n");
    }

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
