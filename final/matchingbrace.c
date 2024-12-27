#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    char * array;
    int size;
    int top;
} Stack;

Stack * createStack ( int size ) {
    Stack * temp = ( Stack * )malloc( sizeof(Stack) );
    temp->array = ( char * )malloc( sizeof(char) * size );
    temp->size = size;
    temp->top = -1;
    return temp;
}

int isEmpty ( Stack * s ) {
    return s->top == -1;
}

void push( Stack *s, char ch ) {
    if ( s->top != s->size - 1 ) {
        s->array[++s->top] = ch;
    } 
}
char pop ( Stack *s ) {
    if ( !isEmpty(s) ) return s->array[s->top--];
    return '$';
}
void matchingBraces ( char * exp ) {
    Stack * s = createStack(10);
    int i = 0;
    int flag = 0;
    while ( exp[i] ) {
        if ( exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ) {
            push(s, exp[i++]);
        } else if ( exp[i] == ')' || exp[i] == '}' || exp[i] == ']' ) {
            if ( isEmpty(s) ) {
                printf("Extra CLOSING braces at index %d \n", i);
                flag = 1;
            }
            else if ( exp[i] == ')' && pop(s) != '(') {
                printf("incorrect braces ) at index %d \n", i);
                flag = 1;
            }
            else if ( exp[i] == '}' && pop(s) != '{') {
                printf("incorrect braces } at index %d \n", i);
                flag = 1;
            }else if ( exp[i] == ']' && pop(s) != '[') {
                printf("incorrect braces ] at index %d \n", i);
                flag = 1;
            }
            i++;
        }

    }
    if ( !isEmpty(s) ) {
        printf("Extra opening braces\n");
    }
    else if ( !flag ) {
        printf("Valid braces\n");
    }
}
int main () {
    matchingBraces("{()}]");
    return 0;
}