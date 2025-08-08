#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int *initStack(int n);
void push(int max, int *top, int *stack);
void pop(int max, int *top, int *stack);
void display(int top, int *stack);

int main() {
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    if(n > MAX_SIZE) {
        printf("Exceeded max Stack size.");
        return 1;
    }
    
    int *stack = initStack(n);
    
    int top = 0;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        int x;
        printf("Enter your choice: ");
        scanf("%d", &x);
        switch (x) {
            case 1:
                push(n, &top, stack);
                break;
            case 2:
                pop(n, &top, stack);
                break;
            case 3:
                free(stack);
                return 0;
            default:
                free(stack);
                printf("Invalid choice\n");
                break;
        }
    }
    
    return 0;
}

int *initStack(int n) {
    int *stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return stack;
}

void push(int max, int *top, int *stack) {
    if(*top < max) {
        int x;
        printf("Enter the element to push: ");
        scanf("%d", &x);
        stack[*top] = x;
        (*top)++;
        display(*top, stack);
    } else {
        printf("Stack is full\n");
    }
}

void pop(int max, int *top, int *stack) {
    if(*top > 0) {
        stack[*top] = 0;
        (*top)--;
        display(*top, stack);
    } else {
        printf("Stack is empty\n");
    }
}

void display(int top, int *stack) {
    for(int i = top - 1; i >= 0; i--) {
        printf("    %d    \n", stack[i]);
        printf("__________\n");
    }
    printf("\n");
}