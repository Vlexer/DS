#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stack{
    int top;
    int size;
    char *s;

} Stack;

int isEmpty( Stack *s ){
    if ( s->top == -1 ) return 1;
    else return 0;
}
int isFull( Stack *s ) {
    if ( s->top == s->size - 1 ) return 1;
    else return 0;

}

int push ( Stack *s, char x ) {
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
        return 0;
    }
}

int isOperand ( char ch ) {
    if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
        return 0;
    } else {
        return 1;
    }
}

int precendence ( char  ch ) {
    if ( ch == '+' || ch == '-' ) return 1;
    if ( ch == '*' || ch == '/' ) return 2;
    if ( ch == '(' ) return -1;
}
void main() {
    char exp[100];
    printf("Enter the Expression \n");
    scanf("%s",exp);
    
    Stack s;
    s.top  = -1;
    s.size = strlen(exp);
    s.s = (char *) malloc( s.size * sizeof(int) );
    char * result = ( char * ) malloc ( sizeof(int) * s.size );
    int i = 0, j = 0;
   
    for ( int i = 0; i < s.size ; i++ )
    {
        char ch = exp[i];
        if ( isOperand(ch) ) {
            result[j++] = ch;
        } else if ( ch == '(' ) {
            push(&s,ch);
        } else if ( ch == ')' ) {
            while ( s.top >= 0 && s.s[s.top] != '(' ) {
                result[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while ( s.top >= 0 && ( precendence(s.s[s.top]) >= precendence(ch) ) ) {
                result[j++] = pop(&s);
            }
            push(&s,ch);
        }
    }
    while ( !isEmpty(&s) ) {
        result[j++] = pop(&s);
    }
    result[j] = '\0';
    printf("%s",result);
}