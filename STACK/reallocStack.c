#include <stdio.h>
#include <stdlib.h>

int push(int **stack, int *size) {
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    int *temp = (int *)realloc(*stack, (*size + 1) * sizeof(int));
    if (temp == NULL) {
        return 1;
    }
    *stack = temp;
    (*stack)[*size] = value;
    (*size)++;
    printf("\nSuccessfully pushed: %d\n", value);
    return 0;
}

int pop(int **stack, int *size) {
    if (*size == 0) {
        printf("\nStack is empty. Nothing to pop.\n");
        return 1;
    }
    (*size)--;
    int *temp = (int *)realloc(*stack, (*size) * sizeof(int));
    if (temp == NULL && *size > 0) {
        return 1;
    }
    *stack = temp;
    printf("\nSuccessfully popped\n");
    return 0;
}

void display(int *stack, int size) {
    if (size == 0) {
        printf("\nStack is empty.\n");
        return;
    }
    for (int i = size - 1; i >= 0; i--) {
        printf(" %d \n", stack[i]);
        printf("__________\n");
    }
}

int main() {
    int *stack = NULL;
    int size = 0;
    while (1) {
        int n;
        printf("\n1. push, 2. pop, 3. display, 4. exit\n");
        printf("Enter a choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                push(&stack, &size);
                break;
            case 2:
                pop(&stack, &size);
                break;
            case 3:
                display(stack, size);
                break;
            case 4:
                free(stack);
                exit(0);
            default:
                free(stack);
                return 1;
        }
    }
    return 0;
}