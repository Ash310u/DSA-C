#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int len) {

    for(int i = 0; i < len; i++) {
        int min = arr[i];
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < min) {
                int temp = arr[j];
                arr[j] = min;
                arr[i] = temp;
            }
        }
    }
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

    selectionSort(arrPtr, n);

    for(int i = 0; i < n; i++) {
        printf("%d", arrPtr[i]);
    }
    free(arrPtr);
    return 0;
}