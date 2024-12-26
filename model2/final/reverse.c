#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int * array;
    int top;
    int size;
} Stack;

Stack * StackInit ( int size ) {
    Stack * temp = ( Stack * )malloc ( sizeof(Stack) );
    temp->array = ( int * )malloc ( sizeof(int) * size );
    temp->top = -1;
    temp->size = size;
    return temp;
}

void push ( Stack * stack, int x ) {
    if ( stack->top == stack->size - 1 ) return;
    stack->array[++stack->top] = x;
} 
#define ERRCODE -1213
int pop ( Stack * stack ) {
    if ( stack->top == -1 ) return ERRCODE;
    return stack->array[stack->top--];
}



void popEverything( Stack * stack ) {
    while ( stack->top != -1 ) {
        printf("%d ", pop(stack));
    }
}

int main () {
    Stack * stack = StackInit(10);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    ReverseStack(stack);
    popEverything(stack);
    return 0;
}