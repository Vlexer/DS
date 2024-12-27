#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    char * array;
    int size;
    int top;
} Stack;

Stack * createStack ( int size ) {
    Stack * temp = ( Stack * )malloc( sizeof(Stack) );
    temp->array = ( char* )malloc( sizeof(char) * size );
    temp->top = -1;
    temp->size = size;
    return temp;
}

void push ( Stack * s, char x ) {
    if( s->top == s->size - 1 ) {
        printf("Stack is full\n");
        return;
    }
    s->array[++s->top] = x;
}

char pop ( Stack *s ) {
    if ( s->top == -1 ) {
        return '$';
    }
    return s->array[s->top--];
}

int isOperator( char c ) {
    if ( c == '+' || c == '-' || c == '*' || c == '/' ) {
        return 1;
    }
    return 0;
}

int precedence ( char c ) {
    if ( c == '+' || c== '-' ) return 1;
    if ( c== '*' || c == '/' || c == '%' ) return 2;
    if ( c== '^' ) return 3;
    return 0;
}

int isEmpty ( Stack * s  ) {
    return s->top == -1;
}  

char peek( Stack * s ) {
    return s->array[s->top];
}

int isDigit ( char c ) {
    return c >= '0' && c <= '9';
}

// void infixToPostfix ( char * infix ) {
//     char postfix[100];
//     Stack * s = createStack(100);
//     int i= 0, j = 0;
//     while ( infix[i] != '\0' ) {
        
//         if ( isDigit(infix[i]) ) {
//             while ( isDigit(infix[i]) ) {
//                 postfix[j++] = infix[i++];
//             }
//             postfix[j++] = ' ';
//         }
//         else if ( infix[i] == '(' ) {
//             push(s, infix[i++]);
//         } else if ( infix[i] == ')' ) {
//             while ( !isEmpty(s) && peek(s) != '(' ) {
//                 postfix[j++] = pop(s);
//                 postfix[j++] = ' ';
//             }
//             pop(s);
//             i++;
//         } else if ( isOperator(infix[i]) ) {
//             while ( !isEmpty(s) && precedence(peek(s)) >= precedence(infix[i]) ) {
//                 postfix[j++] = pop(s);
//                 postfix[j++] = ' ';

//             }
//            push(s, infix[i++]);
//         }
//     }
//     while ( !isEmpty(s) ) {
//         postfix[j++] = pop(s);
//         postfix[j++] = ' ';
//     }
//     postfix[j] = '\0';
//     printf("%s", postfix);
// }

void infixToPostfix ( char * infix ) {
    Stack * stack = createStack(100);
    int i = 0, j = 0;
    char postfix[100];
    while ( infix[i] ) {
        
        if ( isDigit(infix[i]) ) {
            int num = 0;
            while ( isDigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        }else if ( isOperator(infix[i]) ) {
            while ( !isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i]) ) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            push(stack, infix[i++]);
        } else if ( infix[i] == '(' ) {
            push(stack, infix[i++]);
        } else if ( infix[i] == ')' ) {
            while ( !isEmpty(stack) && peek(stack) != '(' ) {
                postfix[j++] = pop(stack);
            }
            pop(stack);
            i++;
        }

    }
    while ( !isEmpty(stack) ) {
        postfix[j++] = pop(stack);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    printf("%s ", postfix);
}


int main () { 

    infixToPostfix("(60+2)-34");
    return 0;
}