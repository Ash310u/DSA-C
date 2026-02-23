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
    
    // Declare and initialize the stack top as 0 (empty stack)
    int top = 0;
    // Dynamically allocate memory for infix input string (up to 49 chars + '\0')
    char *infix = (char *)malloc(50 * sizeof(char));
    // Prompt user for the infix expression
    printf("Enter the infix expression: ");
    // Read the input line (including spaces) into 'infix'
    fgets(infix, 50, stdin);
    // Calculate the length of input string
    int length = strlen(infix);

    // Create an array to hold the postfix output, length same as infix
    char postfix[length];
    // 'j' is postfix output index, 'i' is infix input index
    int j = 0;
    int i = 0;
    // Process each character of the infix expression
    while (i < length) {
        // If space is found, just skip it
        if(infix[i] == ' ') {
            i++;
            continue;
        }
        // If the character is alphanumeric (operand), add to postfix output
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } 
        // If character is '(', push to stack
        else if(infix[i] == '(') {
            push(MAX_SIZE, &top, stack, infix[i]);
        } 
        // If character is ')', pop from stack to postfix until '(' is encountered
        else if(infix[i] == ')') {
            while (top > 0 && stack[top - 1] != '(') {
                postfix[j++] = stack[top - 1];
                pop(MAX_SIZE, &top, stack);
            }
            // Pop the '(' from the stack
            pop(MAX_SIZE, &top, stack);
        } 
        // If character is an operator
        else {
            // Pop operators from stack to postfix as long as they have greater or equal precedence
            while (top > 0 && precedence(infix[i]) <= precedence(stack[top - 1])) {
                postfix[j++] = stack[top - 1];
                pop(MAX_SIZE, &top, stack);
            }
            // Push current operator to stack
            push(MAX_SIZE, &top, stack, infix[i]);
        }
        i++;
    }
    // Pop any remaining operators from stack to postfix
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