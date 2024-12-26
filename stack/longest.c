#include<stdio.h> 
#include<stdlib.h> 

typedef struct Stack {
    int top;
    int size;
    int * s;
} Stack;

Stack * createStack ( int size ) {
    Stack * s = ( Stack * )malloc( sizeof(Stack) );
    s->size = size;
    s->top = -1;
    s->s = ( int * ) malloc( sizeof(int) * size );
    return s;

}

void push( Stack * s, int x ) {
    if ( s->top != s->size - 1 ) {
        s->s[++(s->top)] = x;
    } else {
        printf("Stack is fulL!\n");

    }

}

int pop ( Stack * st ) {
    if ( st->top == -1 ) {
        printf("Stack is Empty!\n");

    } else {
        int poppedElement = st->s[st->top];
        st->top -= 1;
        return poppedElement;
    }
}

int max ( int a, int b ) {
    return ( a > b ) ? a : b;
}


void main () {
    printf("Enter the sequence \n");
    char s[100];
    scanf("%s",s);
    int l = 0;
    for(int i = 0 ; s[i] != '\0' ; i++ ) {
        l++;
    }
    char * input = ( char * ) malloc( sizeof(char) * l );
    for(int i = 0 ; i < l ; i++ ) {
        input[i] = s[i];
    }
    Stack * st = createStack(l);
    push( st, -1 );
    int maxLength = 0;

    for ( int i = 0 ; i < l ; i++ ) {
       
        if ( input[i] == '(' ){
            push(st, i);
        } else {
            int temp = pop(st);
            if ( st->top == -1 ) {
                push(st, i);
            } else {
                
                maxLength = max( maxLength, i - st->s[st->top]  );
            }
        }
    }
    printf("max length = %d",maxLength);
}