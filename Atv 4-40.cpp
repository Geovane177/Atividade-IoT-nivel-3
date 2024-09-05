#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                printf("---");
                if (j < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;

    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int row, col;

    // Initialize board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Bem-vindo ao jogo da velha!\n");

    while (1) {
        printBoard(board);

        // Input
        printf("Jogador %c, entre com a linha e coluna (0-2) separados por espaço: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Entrada inválida! Tente novamente.\n");
            continue;
        }

        if (board[row][col] != ' ') {
            printf("Espaço já ocupado! Tente novamente.\n");
            continue;
        }

        // Atualiza o tabuleiro
        board[row][col] = currentPlayer;

        // Verifica se o jogador atual ganhou
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            printf("Jogador %c venceu!\n", currentPlayer);
            break;
        }

        // Verifica se o tabuleiro está cheio
        if (isBoardFull(board)) {
            printBoard(board);
            printf("Empate!\n");
            break;
        }

        // Troca o jogador
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
