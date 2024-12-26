#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    char* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(Stack* stack, char item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

// Function to remove an item from stack. It decreases top by 1
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; // Return a null character if stack is empty
}

// Function to check if the parentheses are valid
int isValid(char* expr) {
    Stack* stack = createStack(100); // You can adjust the size as needed

    for (int i = 0; expr[i]; i++) {
        // If the character is an opening bracket, push it to the stack
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(stack, expr[i]);
        }
        // If it is a closing bracket
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            // If the stack is empty or top of the stack does not match
            if ( isEmpty(stack) || (expr[i] == ')' && pop(stack) != '(') || (expr[i] == '}' && pop(stack) != '{') || (expr[i] == ']' && pop(stack) != '[') ) {
                return 0;
            }
        }
    }

    // If the stack is empty, all brackets are matched
    int result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expr[100];
    
    printf("Enter a string of parentheses: ");
    scanf("%s", expr);
    
    if (isValid(expr)) {
        printf("The parentheses are valid.\n");
    } else {
        printf("The parentheses are not valid.\n");
    }

    return 0;
}
