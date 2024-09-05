#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Fun��o para imprimir o tabuleiro de Sudoku com espa�amento
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Imprimir um espa�o extra a cada 3 colunas
            if (j % 3 == 0 && j != 0) {
                printf(" | ");
            }
            printf("%d ", board[i][j]);
        }
        printf("\n");

        // Imprimir uma linha separadora a cada 3 linhas
        if ((i + 1) % 3 == 0 && i != SIZE - 1) {
            printf("---------------------\n");
        }
    }
    printf("\n");
}

// Fun��o para verificar se um n�mero pode ser colocado em uma posi��o espec�fica
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {
    // Verificar se o n�mero j� est� na linha
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Verificar se o n�mero j� est� na coluna
    for (int x = 0; x < SIZE; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Verificar se o n�mero j� est� no bloco 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Fun��o para encontrar a pr�xima posi��o vazia no tabuleiro
bool findEmptyLocation(int board[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Fun��o recursiva para resolver o Sudoku
bool solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    // Se n�o h� mais espa�os vazios, o Sudoku est� resolvido
    if (!findEmptyLocation(board, &row, &col)) {
        return true;
    }

    // Tentar colocar n�meros de 1 a 9 na posi��o encontrada
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recursivamente tentar resolver o restante do Sudoku
            if (solveSudoku(board)) {
                return true;
            }

            // Se o n�mero n�o levar a uma solu��o, desfazer a coloca��o
            board[row][col] = 0;
        }
    }

    // Se nenhum n�mero � v�lido, retornar falso
    return false;
}

int main() {
    // Exemplo de tabuleiro de Sudoku com alguns n�meros j� preenchidos
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Imprimir o tabuleiro antes de resolver
    printf("Tabuleiro de Sudoku antes de resolver:\n");
    printBoard(board);

    // Resolver o Sudoku
    if (solveSudoku(board)) {
        printf("Sudoku resolvido:\n");
        printBoard(board);
    } else {
        printf("Nenhuma solu��o encontrada.\n");
    }

    return 0;
}

