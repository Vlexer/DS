#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stack{
    int top;
    int size;
    int *s;

} Stack;

int isEmpty( Stack *s ){
    if ( s->top == -1 ) return 1;
    else return 0;
}
int isFull( Stack *s ) {
    if ( s->top == s->size - 1 ) return 1;
    else return 0;

}

int push ( Stack *s, int x ) {
    if ( !isFull(s) ) {
        s->s[++(s->top)] = x;
    } else {
        printf("Stack full\n");
    }

}

char pop ( Stack *s ) {
    if ( !isEmpty(s) ) {
        int x = s->s[s->top];
        s->top--;
        return x;
    } else {
        printf("Stack is empty\n");
    }
}

void main() {
    char temp[1000];
    printf("Enter an expression with braces\n");
    scanf("%s",temp);
    char * exp = (char *) malloc( strlen(temp) * sizeof(char) );
    strcpy(exp,temp);
    Stack s;
    s.top = -1;
    s.size = strlen(exp);
    s.s = (int * ) malloc( s.size * sizeof(int) );
    for ( int i = 0; i < s.size ; i++  ){
        if ( exp[i] == '(' ) {
            push(&s, i);

        } else if ( exp[i] == ')' ) {
            if (isEmpty(&s)) {
                printf("Invalid cuz of extra closing brace at index %d\n",i);
                exit(-1);
            } else {
                pop(&s);
            }

        }

    }
    if ( isEmpty(&s) ) {

        printf("Valid expression\n");
    } else {
        printf("Not a valid expression cuz of more opening braces at index %d\n",s.s[s.top]);
    }

}