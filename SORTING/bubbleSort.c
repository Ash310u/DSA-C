#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int len) {

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int *arrPtr = (int *)malloc(n * sizeof(int));
    if(arrPtr != NULL)
        printf("Enter the size of the array: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arrPtr[i]);
    }

    bubbleSort(arrPtr, n);

    for(int i = 0; i < n; i++) {
        printf("%d", arrPtr[i]);
    }
    free(arrPtr);
    return 0;
}