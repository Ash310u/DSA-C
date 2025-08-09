#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

union Data {
    int i;
    float f;
    char str[20];
};

typedef struct {
    union Data data;
    int type;  // 0 = int, 1 = float, 2 = string
} Element;

typedef struct Stack {
    Element elements[MAX_SIZE];
    int top;
} Stack;
    
Stack *initStack(int n);
void push(int max, Stack *ptr);
void pop(int max, Stack *ptr);
void display(Stack *ptr);

int main() {
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    if(n > MAX_SIZE) {
        printf("Exceeded max Stack size.");
        return 1;
    }
    
    Stack *stack = initStack(n);
    
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        int x;
        printf("Enter your choice: ");
        scanf("%d", &x);
        switch (x) {
            case 1:
                push(n, stack);
                break;
            case 2:
                pop(n, stack);
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

Stack *initStack(int n) {
    Stack *stack = (Stack *)malloc(n * sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = 0;
    return stack;
}
void push(int max, Stack *stack) {
    if (stack->top >= max) {
        printf("Stack is full\n");
        return;
    }

    int choice;
    printf("Select data type to push:\n");
    printf("1. Integer\n2. Float\n3. String\n");
    scanf("%d", &choice);

    Element e;
    e.type = choice - 1;

    switch (e.type) {
        case 0:
            printf("Enter integer: ");
            scanf("%d", &e.data.i);
            break;
        case 1:
            printf("Enter float: ");
            scanf("%f", &e.data.f);
            break;
        case 2:
            printf("Enter string: ");
            scanf("%s", e.data.str);
            break;
        default:
            printf("Invalid type\n");
            return;
    }

    stack->elements[stack->top++] = e;
    display(stack);
}

void pop(int max, Stack *stack) {
    if (stack->top <= 0) {
        printf("Stack is empty\n");
        return;
    }

    stack->top--;
    Element e = stack->elements[stack->top];

    printf("Popped value: ");
    switch (e.type) {
        case 0:
            printf("%d\n", e.data.i);
            break;
        case 1:
            printf("%f\n", e.data.f);
            break;
        case 2:
            printf("%s\n", e.data.str);
            break;
    }

    display(stack);
}

void display(Stack *stack) {
    printf("\nStack contents:\n");
    for (int i = stack->top - 1; i >= 0; i--) {
        Element e = stack->elements[i];
        switch (e.type) {
            case 0:
                printf("         %d        \n", e.data.i);
                break;
            case 1:
                printf("      %f     \n", e.data.f);
                break;
            case 2:
                printf("%s\n", e.data.str);
                break;
        }
        printf("____________________\n");
    }
    printf("\n");
}