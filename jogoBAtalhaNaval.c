#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

// 0 = água
// 3 = navio
// 2 = área atacada sem acerto
// 1 = acerto no navio

int tabuleiro[TAM][TAM] = {0};

void exibirTabuleiro() {
    printf("   ");
    for (int j = 0; j < TAM; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// FUNÇÃO PARA POSICIONAR NAVIO
int posicionarNavio(int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int nl = linha + i * dLinha;
        int nc = coluna + i * dColuna;
        if (nl < 0 || nl >= TAM || nc < 0 || nc >= TAM) return 0;
        if (tabuleiro[nl][nc] != 0) return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i * dLinha][coluna + i * dColuna] = 3;
    }
    return 1;
}

// ======== SKILLS ========

// Skill 1: Cone
int skillCone[3][5] = {
    {0, 0, 3, 0, 0},
    {0, 3, 3, 3, 0},
    {3, 3, 3, 3, 3}
};

// Skill 2: Cruz (+)
int skillCruz[3][5] = {
    {0, 0, 3, 0, 0},
    {3, 3, 3, 3, 3},
    {0, 0, 3, 0, 0}
};

// Skill 3: Octaedro (X)
int skillOctaedro[3][5] = {
    {0, 0, 3, 0, 0},
    {0, 3, 3, 3, 0},
    {0, 0, 3, 0, 0}
};

void aplicarSkill(int skill[3][5], int linha, int coluna) {

    if (linha + 3 > TAM || coluna + 5 > TAM) {
        printf("Skill fora do tabuleiro!\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (skill[i][j] == 3) {
                int nl = linha + i;
                int nc = coluna + j;

                if (tabuleiro[nl][nc] == 3)
                    tabuleiro[nl][nc] = 1; // Acertou navio
                else if (tabuleiro[nl][nc] == 0)
                    tabuleiro[nl][nc] = 2; // Erro
            }
        }
    }
}

int main() {
    int linha, coluna, escolha;

    // Posicionar navios (fixos)
    posicionarNavio(2, 4, 0, 1);   // →
    posicionarNavio(5, 7, 1, 0);   // ↓
    posicionarNavio(0, 0, 1, 1);   // ↘
    posicionarNavio(3, 7, 1, -1);  // ↙

    printf("\n Tabuleiro inicial:\n");
    exibirTabuleiro();

    printf("\n Escolha sua Skill:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro\n");
    scanf("%d", &escolha);

    printf("\nInforme a linha e coluna de ataque: ");
    scanf("%d %d", &linha, &coluna);

    switch (escolha) {
        case 1: aplicarSkill(skillCone, linha, coluna); break;
        case 2: aplicarSkill(skillCruz, linha, coluna); break;
        case 3: aplicarSkill(skillOctaedro, linha, coluna); break;
        default: printf("Opção inválida!\n"); return 0;
    }

    printf("\n Tabuleiro após skill:\n");
    exibirTabuleiro();

    return 0;
}
