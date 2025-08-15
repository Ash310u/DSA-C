#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 50

char *initStack(int n);
void push(int max, int *top, char *stack, char infix);
int pop(int max, int *top, char *stack);
void display(int top, char *stack);

int precedence(char c);
void postFix(char *infix, int n, int *top, char*stack);

int main() {
    char *stack = initStack(MAX_SIZE);
    
    int top = 0;
    char *infix = (char *)malloc(50 * sizeof(char));
    printf("Enter the infix expression: ");
    fgets(infix, 50, stdin);
    int length = strlen(infix);

    postFix(infix, length, &top, stack);
    free(infix);
    free(stack);
    return 0;
}

char *initStack(int n) {
    char *stack = (char *)malloc(n * sizeof(char));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return stack;
}

void push(int max, int *top, char *stack, char infix) {
    if(*top < max) {
        stack[*top] = infix;
        (*top)++;
        display(*top, stack);
    } else {
        printf("Stack is full\n");
    }
}

int pop(int max, int *top, char *stack) {
    if(*top > 0) {
        (*top)--;
        char val = stack[*top];
        stack[*top] = '\0';
        display(*top, stack);
        return val;
    } else {
        printf("Stack is empty\n");
        return '\0';
    }
}

void display(int top, char *stack) {
    for(int i = top - 1; i >= 0; i--) {
        printf("    %c    \n", stack[i]);
        printf("__________\n");
    }
    printf("\n");
}

int precedence(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return 0;
    }
}

void postFix(char *infix, int n, int *top, char *stack) {
    char *postfix = (char *)malloc((n + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i < n; ) {
        if(infix[i] == '(') {
            push(n, top, stack, infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while(*top > 0 && stack[*top - 1] != '(') {
                postfix[j] = pop(n, top, stack);
                j++;
            }
            pop(n, top, stack);
            i++;
        } else if (isalnum(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            while (*top > 0 && precedence(infix[i]) <= precedence(stack[*top - 1])) {
                postfix[j] = pop(n, top, stack);
                j++;
            }
            push(n, top, stack, infix[i]);
            i++;
        }
    }
    printf("Postfix expression: ");
    for(int i = 0; i < j; i++) {
        printf("%c", postfix[i]);
        if(i < j-1) {
            printf(" ");
        }
    }
    printf("\n");
    free(postfix);
}