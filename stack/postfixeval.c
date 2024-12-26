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

int isOperand ( char ch ) {
    if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
        return 0;
    } else {
        return 1;
    }
}

int precendence ( char  ch ) {
    if ( ch == '+' || ch == '-' ) return 1;
    if ( ch == '*' || ch == '/' ) return 2;
}
void main() {
    char temp[1000];
    printf("Enter an expression with braces\n");
    scanf("%s",temp);
    char * exp = (char *) malloc( strlen(temp) * sizeof(char) );
    strcpy(exp,temp);
    Stack s;
    s.top  = -1;
    s.size = strlen(exp);
    s.s = (int *) malloc( s.size * sizeof(int) );
    for ( int i = 0; i < s.size ; i++ ) {
        char ch = exp[i];
        if ( isOperand(ch) ) {
            push(&s,ch - '0');
        } else {
            int x = pop(&s);
            int y = pop(&s);
            int result;
            switch (ch)
            {
            case '+':
              { 
                result = y + x;
                 /* code */
                break;
              }
            case '-': {
                result = y - x;
                break;
            } case '*':{
                result = y * x;
                break;
            } case '/':
            {
                result = y / x;
                break;
            }
            }
            push(&s,result);
        }

    }
    printf("Answer =  %d",pop(&s));
}