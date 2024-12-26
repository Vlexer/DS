#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack {
    int size;
    int top;
    int *stack;
} Stack;

bool isFull(Stack *s) {
    return s->top == s->size - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int x) {
    if (isFull(s)) {
        printf("The Stack is full\n");
    } else {
        s->stack[++(s->top)] = x;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("The Stack is empty\n");
        return __INT_MAX__;
    } else {
        int popped = s->stack[s->top];
        s->top -= 1;
        return popped;
    }
}

Stack *createStack(int size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = size;
    s->top = -1;
    s->stack = (int *)malloc(sizeof(int) * size);
    return s;
}

int main() {
    int size, min = __INT_MAX__, ch;
    printf("Enter the size of the stack\n");
    scanf("%d", &size);
    Stack *s = createStack(size);

    printf("Enter 1 to push, 2 to pop, 3 to get min, 4 to exit\n");
    scanf("%d", &ch);

    while (ch != 4) {
        switch (ch) {
            case 1: {
                int x;
                printf("Enter the element to push\n");
                scanf("%d", &x);
                if (isEmpty(s)) {
                    min = x;
                    push(s, x);
                } else if (x < min) {
                    // Push modified value and update min
                    push(s, 2 * x - min);
                    min = x;
                } else {
                    push(s, x);
                }
                break;
            }
            case 2: {
                if (isEmpty(s)) {
                    printf("The Stack is empty\n");
                } else {
                    int x = pop(s);
                    if (x < min) {
                        // Pop the modified value and adjust min
                        printf("Popped element is %d\n", min);
                        min = 2 * min - x;
                    } else {
                        printf("Popped element is %d\n", x);
                    }
                }
                break;
            }
            case 3: {
                if (isEmpty(s)) {
                    printf("The Stack is empty\n");
                } else {
                    printf("Min = %d\n", min);
                }
                break;
            }
            default: {
                printf("Invalid choice, please enter 1 to push, 2 to pop, 3 to get min, 4 to exit\n");
            }
        }
        printf("Enter 1 to push, 2 to pop, 3 to get min, 4 to exit\n");
        scanf("%d", &ch);
    }

    // Free the memory allocated for the stack
    free(s->stack);
    free(s);

    return 0;
}
