#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isSafe(int **board, int n, int row, int col) {
    int i, j;

    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) return 0;
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return 0;
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return 0;
    }

    return 1;
}

void printBoard(int **board, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int solve(int **board, int n, int row, int *count) {
    int col;
    if (row == n) {
        // printBoard(board, n);
        (*count)++;
        return 0; // continue searching for all solutions
    }

    for (col = 0; col < n; col++) {
        if (isSafe(board, n, row, col)) {
            board[row][col] = 1;

            solve(board, n, row + 1, count);

            board[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int n;
    int i;
    int **board;
    int solutions = 0;

    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    clock_t start = clock();

    board = (int **)malloc(n * sizeof(int *));
    if (board == NULL) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        board[i] = (int *)calloc(n, sizeof(int));
        if (board[i] == NULL) {
            while (--i >= 0) {
                free(board[i]);
            }
            free(board);
            return 0;
        }
    }

    solve(board, n, 0, &solutions);

    if (solutions == 0) {
        printf("No solution exists\n");
    } else {
        printf("Total solutions: %d\n", solutions);
    }

    for (i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    
    clock_t end = clock();
    
    double cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", cpu_time);
    return 0;
}