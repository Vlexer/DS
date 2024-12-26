#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    
    while (infix[i]) {
        if (isdigit(infix[i])) {
            // Add two-digit numbers to the output
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Separate numbers by space
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
            i++;
        } else if ( infix[i] == ')' ) {
            while ( !isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            pop(&stack); // Pop the '('
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, infix[i]);
            i++;
        } else {
            i++; // Skip whitespace or unrecognized characters
        }
    }

    // Pop all operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0'; // Null-terminate the output string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (two-digit numbers allowed): ");
    fgets(infix, MAX, stdin);
    
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
