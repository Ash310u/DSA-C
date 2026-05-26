#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++) 
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
            min = count;
    }

    return min;
}

int main()
{
    int n;

    printf("Enter number of matrices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return 1;
        }
    }

    printf("Minimum number of multiplications is %d\n",
        MatrixChainOrder(arr, 1, n));

    free(arr);
    return 0;
}