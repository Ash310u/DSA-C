#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void display(int top, int *stack, int n) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (bottom to top): ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push(int max, int *top, int *stack, int n) {
    if (*top >= max - 1) {
        printf("Stack is full\n");
        return;
    }
    int x;
    printf("Enter the element to push: ");
    scanf("%d", &x);
    (*top)++;
    stack[*top] = x;
    display(*top, stack, n);
}

void pop(int *top, int *stack, int n) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return;
    }
    (*top)--;
    display(*top, stack, n);
}

int main() {
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Exceed max Stack size.");
        return 1;
    }

    int *stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL) {
        printf("Memory Allocation Error.");
        return 1;
    }

    int top = -1; // Start the stack from -1
    while (1) {
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Exit\n");

        int x;
        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                push(n, &top, stack, n); // Last element is on top, use 0-based index
                break;
            case 2:
                pop(&top, stack, n);
                break;
            case 3:
                free(stack);
                return 0;
            default:
                free(stack);
                printf("Invalid choice\n");
                return 1;
        }
    }

    return 0;
}