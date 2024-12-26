#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
typedef struct Stack { 
    int size;
    int top;
    int * stack;
} Stack;

bool isFull( Stack * s ) {
    return s->top == s->size - 1;
}
bool isEmpty ( Stack * s ) {
    return s->top == -1;
}

void push (Stack * s, int  x) {
    if ( isFull(s) ) {
        printf("The Stack is full\n");
    } else {
        s->stack[++(s->top)] = x;
    }
} 
int  pop ( Stack * s ) {
    if ( isEmpty(s) ) {
        printf("The Stack is empty\n");
        return __INT_MAX__;
    } else{
        
        int popped = s->stack [s->top];
        s->top -= 1; 
        return popped;   
    }
}
int insert( Stack *s, int x ) {
    if ( isEmpty(s) ) push(s,x);
    else{
        if ( x > s->stack[s->top] ) {
            int y = pop(s);
            insert(s,x);
            push(s, y);
        }
        else {
            push(s, x);
        }
    }

}

void sort ( Stack * s ) {
    if ( isEmpty(s) ) {
        return;
    }
    int y = pop(s);
    sort(s);
    insert(s, y);
} 

Stack * createStack(int size ) {
    Stack * s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->stack = ( int * ) malloc( sizeof(int) * size );
    s->size = size;
    return s;
}



void main () {
    Stack * s = createStack(5);
    push(s, 3);
    push(s, 2);
    push(s, -5);
    push(s, 6);
    push(s, -1);
    sort(s);
    while( !isEmpty(s)) {
        printf("%d ", pop(s));
    }
    
}