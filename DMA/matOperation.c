#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Dynamic memory allocation for n x n matrix
int **allocMatrix(int n) {
    int **mat = (int **)malloc(n * sizeof(int *));
    if (!mat) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (!mat[i]) {
            printf("Memory allocation failed\n");
            // Free previously allocated rows
            for (int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            exit(1);
        }
    }
    return mat;
}

// Free dynamically allocated n x n matrix
void freeMatrix(int **mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

// Generalized input function for any n x n matrix (DMA)
void inputMatrix(int **mat, int n, const char *prompt) {
    if (prompt) printf("%s", prompt);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
}

// Generalized print function for any n x n matrix (DMA)
void printMatrix(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Transpose for DMA matrix
void transpose(int **mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    printf("Transpose of the matrix:\n");
    printMatrix(mat, n);
}

// Addition for DMA matrices
void addMatrices(int **mat1, int **mat2, int n) {
    int **sum = allocMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum[i][j] = mat1[i][j] + mat2[i][j];
    printf("Sum of matrices:\n");
    printMatrix(sum, n);
    freeMatrix(sum, n);
}

// Insert element in n x n DMA matrix at position pos (1-based, row-major order)
int insertElement(int **mat, int insert, int pos, int n) {
    if (pos < 1 || pos > n * n + 1) {
        printf("Invalid position!\n");
        return 1;
    }
    int count = 1;
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count == pos) {
                temp = mat[i][j];
                mat[i][j] = insert;
                insert = temp;
                pos++;
            }
            count++;
        }
    }
    printf("Matrix after insertion:\n");
    printMatrix(mat, n);
    return 0;
}

int main() {
    char choice;
    printf("What do you want to do?\n");
    printf("T - Transpose\nA - Addition\nI - Insertion\nEnter your choice: ");
    scanf(" %c", &choice);
    choice = toupper(choice);

    int n;

    switch (choice) {
        case 'T': {
            printf("Enter matrix size: ");
            scanf("%d", &n);
            int **mat = allocMatrix(n);
            inputMatrix(mat, n, NULL);
            transpose(mat, n);
            freeMatrix(mat, n);
            break;
        }
        case 'A': {
            printf("Enter matrix size: ");
            scanf("%d", &n);
            int **mat1 = allocMatrix(n);
            int **mat2 = allocMatrix(n);
            inputMatrix(mat1, n, "Enter first matrix:\n");
            inputMatrix(mat2, n, "Enter second matrix:\n");
            addMatrices(mat1, mat2, n);
            freeMatrix(mat1, n);
            freeMatrix(mat2, n);
            break;
        }
        case 'I': {
            printf("Enter matrix size: ");
            scanf("%d", &n);
            int **mat = allocMatrix(n);
            inputMatrix(mat, n, "Enter elements of matrix:\n");
            int insert, pos;
            printf("Enter the element to insert: ");
            scanf("%d", &insert);
            printf("Enter position to insert (1 to %d): ", n * n + 1);
            scanf("%d", &pos);
            insertElement(mat, insert, pos, n);
            freeMatrix(mat, n);
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}