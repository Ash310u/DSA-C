#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    printf("left: %d, right: %d\n", left, right);
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    int *arrPtr = (int *)malloc(n * sizeof(int));
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arrPtr[i]);
    }
    mergeSort(arrPtr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        printf("%d ", arrPtr[i]);
    }
    free(arrPtr);
    return 0;
}