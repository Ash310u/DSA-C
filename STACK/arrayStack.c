#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void display(int top, int *stack) {
    for(int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void push(int max, int *top, int *stack) {
    if(*top >= max) {
        printf("Stack is full\n");
        return;
    }
    int x;
    printf("Enter the element to push: ");
    scanf("%d", &x);
    stack[*top] = x;
    (*top)++;
    display(*top, stack); 
}

void pop(int *top, int *stack) {
    if(*top <= 0) {
        printf("Stack is empty\n");
        return;
    }
    (*top)--;
    stack[*top] = 0;
    display(*top, stack); 
}

int main() {
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    if(n > MAX_SIZE) {
        printf("Exceed max Stack size.");
        return 1;
    }

    int *stack = (int *)malloc(n * sizeof(int));
    if(stack == NULL) {
        printf("Memory Allocation Error.");
        return 1;
    }
    
    int top = 0;
    while(1) {
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Exit\n");

        int x;
        printf("Enter your choice: ");
        scanf("%d", &x);

        switch(x) {
            case 1:
                push(n, &top, stack); // Use 'n' instead of MAX_SIZE for user-specified size
                break;
            case 2: 
                pop(&top, stack);
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