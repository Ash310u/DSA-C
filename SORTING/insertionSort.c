#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int len) {
    for(int i = 1; i < len; i++) {
        int curr = arr[i];
        int j;
        // j-- happens after arr[j+1] = arr[j], so after shifting arr[j] to the right,
        // j is decremented and points to the previous element for the next comparison/shift.
        for (j = i - 1; j >= 0 && arr[j] > curr; j--) {
            arr[j + 1] = arr[j];
        }
        // When the loop ends, j is at the position BEFORE where curr should go, so arr[j+1] is the correct spot for curr.
        arr[j + 1] = curr;
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