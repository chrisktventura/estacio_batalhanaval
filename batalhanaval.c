#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função auxiliar para valor absoluto de inteiros
int absInt(int x) {
    return x < 0 ? -x : x;
}

// Exibe o tabuleiro com símbolos visuais
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (tabuleiro[i][j] == 0)
            {
                printf("~ ");
            }
            else if (tabuleiro[i][j] == 3)
            {
                printf("O ");
            }
            else if (tabuleiro[i][j] == 5)
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Habilidade em forma de cone (triângulo com vértice no topo)
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE])
{
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (j >= (TAMANHO_HABILIDADE / 2) - i && j <= (TAMANHO_HABILIDADE / 2) + i)
            {
                habilidade[i][j] = 1;
            }
            else
            {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Habilidade em cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE])
{
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2)
            {
                habilidade[i][j] = 1;
            }
            else
            {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Habilidade em forma de octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE])
{
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (absInt(i - centro) + absInt(j - centro) <= centro)
            {
                habilidade[i][j] = 1;
            }
            else
            {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma matriz de habilidade no tabuleiro
void aplicarHabilidadeNoTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna)
{
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            int linha = origemLinha + i - TAMANHO_HABILIDADE / 2;
            int coluna = origemColuna + j - TAMANHO_HABILIDADE / 2;
            if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO)
            {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

int main()
{
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionando navios manualmente
    tabuleiro[2][3] = 3;
    tabuleiro[5][6] = 3;

    // Criando matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Aplicando habilidades no tabuleiro
    aplicarHabilidadeNoTabuleiro(tabuleiro, cone, 3, 3);     // Cone em (3,3)
    aplicarHabilidadeNoTabuleiro(tabuleiro, cruz, 5, 5);     // Cruz em (5,5)
    aplicarHabilidadeNoTabuleiro(tabuleiro, octaedro, 7, 7); // Octaedro em (7,7)

    // Exibir resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}
