#include <stdio.h>

int main() {

    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    int tabuleiro[10][10];

    int navio1Linha = 2;
    int navio1Coluna = 4;

    int navio2Linha = 5;
    int navio2Coluna = 7;

    // Inicializa o tabuleiro com água
    for(int i = 0; i < tamanhoTabuleiro; i++){
        for(int j = 0; j < tamanhoTabuleiro; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Valida limites dos navios
    if (navio1Coluna + tamanhoNavio > tamanhoTabuleiro) {
        printf("Erro: Navio 1 está fora do limite.\n");
        return 1;
    }
    if (navio2Linha + tamanhoNavio > tamanhoTabuleiro) {
        printf("Erro: Navio 2 está fora do limite.\n");
        return 1;
    }

    // Posiciona navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[navio1Linha][navio1Coluna + i] = 3;
    }

    // Verifica sobreposição do navio 2
    for (int i = 0; i < tamanhoNavio; i++) {
        if (tabuleiro[navio2Linha + i][navio2Coluna] == 3) {
            printf("Erro: Navio 2 sobrepõe o Navio 1.\n");
            return 1;
        }
    }

    // Posiciona navio vertical
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[navio2Linha + i][navio2Coluna] = 3;
    }

    printf("\n======= TABULEIRO BATALHA NAVAL =======\n\n");

    // Cabeçalho com letras A-J
    printf("   ");
    for (int j = 0; j < tamanhoTabuleiro; j++) {
        printf("%c ", 'A' + j); // converte número para letra do alfabeto
    }
    printf("\n");

    // Linhas com números + valores do tabuleiro
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%2d ", i);
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda:\n0 = Água \n3 = Navio \n\n");

    return 0;
}