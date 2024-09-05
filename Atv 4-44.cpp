#include <stdio.h>

#define N 8

// Movimentos poss�veis do cavalo em um tabuleiro de xadrez
int moveX[] = {2, 2, -2, -2, 1, 1, -1, -1};
int moveY[] = {1, -1, 1, -1, 2, -2, 2, -2};

// Fun��o para verificar se uma posi��o est� dentro dos limites do tabuleiro
int isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Fun��o para imprimir o tabuleiro com a posi��o do cavalo
void printBoard(int board[N][N], int knightX, int knightY) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == knightX && j == knightY)
                printf(" K ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Fun��o para simular os movimentos do cavalo
void simulateKnightMoves(int x, int y) {
    printf("Movimentos possiveis do cavalo a partir da posicao (%d, %d):\n", x, y);

    // Imprimir o tabuleiro
    int board[N][N] = {0};
    printBoard(board, x, y);

    // Testar todos os movimentos poss�veis
    for (int i = 0; i < 8; i++) {
        int newX = x + moveX[i];
        int newY = y + moveY[i];
        if (isValid(newX, newY)) {
            printf("Movimento para (%d, %d)\n", newX, newY);
        }
    }
}

int main() {
    int x, y;

    printf("Digite a posicao inicial do cavalo (x y): ");
    scanf("%d %d", &x, &y);

    // Verificar se a posi��o inicial est� dentro dos limites do tabuleiro
    if (!isValid(x, y)) {
        printf("Posi��o invalida! As coordenadas devem estar entre 0 e 7.\n");
        return 1;
    }

    simulateKnightMoves(x, y);

    return 0;
}
