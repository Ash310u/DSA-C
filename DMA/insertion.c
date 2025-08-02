#include <stdio.h>
#include <stdlib.h>

int **inputMatrix(int n) {
    int **mat = (int **)malloc(n * sizeof(int *));
    if (mat == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

void printMatrix(int **mat, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void insertElement(int **mat, int insert, int pos, int n) {
    int count = 1;
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(count == pos) {
                temp = mat[i][j];
                mat[i][j] = insert;
                insert = temp;
                pos++;
            }
            count++;
        }
    }
}

int main() {
    int n;
    printf("Enter the Size of the array: ");
    scanf("%d", &n);
    printf("-----------------------------\n");    
    int insert;
    int pos;

    printf("Enter elements of %dx%d matrix:\n", n, n);
    int **ptr = inputMatrix(n);

    printf("Enter the element to insert: ");
    scanf("%d", &insert);

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    insertElement(ptr, insert, pos, n);

    printf("Matrix after insertion:\n");
    printMatrix(ptr, n);

    for (int i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);
    
    return 0;
}