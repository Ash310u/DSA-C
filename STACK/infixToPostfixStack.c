#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 50

char *initStack(int n);
void push(int max, int *top, char *stack, char infix);
void pop(int max, int *top, char *stack);
int precedence(char c);

int main() {
    char *stack = initStack(MAX_SIZE);
    
    int top = 0;
    char *infix = (char *)malloc(50 * sizeof(char));
    printf("Enter the infix expression: ");
    fgets(infix, 50, stdin);
    int length = strlen(infix);

    char postfix[length];
    int j = 0;
    int i = 0;
    while (i < length) {
        if(infix[i] == ' ') {
            i++;
            continue;
        }
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if(infix[i] == '(') {
            push(MAX_SIZE, &top, stack, infix[i]);
        } else if(infix[i] == ')') {
            while (top > 0 && stack[top - 1] != '(') {
                postfix[j++] = stack[top - 1];
                pop(MAX_SIZE, &top, stack);
            }
            pop(MAX_SIZE, &top, stack);
        } else {
            while (top > 0 && precedence(infix[i]) <= precedence(stack[top - 1])) {
                postfix[j++] = stack[top - 1];
                pop(MAX_SIZE, &top, stack);
            }
            push(MAX_SIZE, &top, stack, infix[i]);
        }
        i++;
    }
    while (top > 0) {
        postfix[j++] = stack[top - 1];
        pop(MAX_SIZE, &top, stack);
    }
    printf("Postfix expression: ");
    for (int i = 0; i < j; i++) {
        printf("%c", postfix[i]);
    }
    printf("\n");
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
    } else {
        printf("Stack is full\n");
    }
}

void pop(int max, int *top, char *stack) {
    if(*top > 0) {
        (*top)--;
        stack[*top] = '\0';
    } else {
        printf("Stack is empty\n");
    }
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