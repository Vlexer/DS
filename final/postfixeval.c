#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int * array;
    int top;
    int size;
} Stack;

Stack * createStack ( int size ) {
    Stack * temp = ( Stack * )malloc ( sizeof(Stack) );
    temp->array  = ( int * ) malloc ( sizeof( int ) * size );
    temp->size = size;
    temp->top = -1;
}
 
int isEmpty ( Stack * s ) {
    return s->top == -1;
}

void push ( Stack *s, int x ) {
    if ( s->top != s->size - 1 ) {
        s->array[++s->top] = x;
    }
}

int pop ( Stack * s ) {
    if ( !isEmpty ( s ) ) {
        return s->array[s->top--];
    }
}
int isDigit ( char c ) {
    return c >= '0' && c <= '9';
}
int isOperator ( char c ) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
// void postfixEval ( char * exp ) {
//     Stack * s = createStack(10);
//     int i = 0;
//     while ( exp[i] != '\0' ) {
//         if ( isDigit(exp[i]) ) {
//             int num = 0;
//             while ( isDigit(exp[i]) ) {
//                 num = num * 10 + (int)( exp[i] - '0' );
//                 i++;
//             }
//             push(s, num);
//         }
//         else if ( isOperator(exp[i])) {
//             int n1 = pop(s);
//             int n2 = pop(s);
//             switch ( exp[i] ) {
//                 case '+': {
//                     push(s, n1 + n2);
//                     break;
//                 } case '-' :
//                 {
//                     push(s, n1 - n2);
//                     break;
//                 }
//                 case '*':{ 
//                     push(s, n1 * n2);
//                     break;;
//                 }
//                 case '/':{
//                     push( s, n1/n2);
//                 }
//             }

//         }
//         i++;
//     }
//     printf("Result = %d\n", pop(s));
// }

int postfixEval ( char * postfix ) {
    Stack * stack =createStack(100);
    int i = 0;
    while( postfix[i] != '\0') {
        printf("%c ", postfix[i]);
        if ( isDigit(postfix[i]) ) {
            int num = 0;
            while ( isDigit(postfix[i]) ) {
                printf("%d ", num);
                num = num * 10 + ( postfix[i] - '0' );
                i++;
            }
            push(stack, num);
        }
        else if ( isOperator(postfix[i]) ) {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch ( postfix[i] ) {
                case '+':{
                    push(stack, val1 + val2);
                    break;
                } case '-' :
                {
                    push(stack, val1 - val2);
                    break;
                } case '*':
                {
                    push(stack, val1 * val2);
                    break;
                }
                case '/':
                {
                    push(stack, val1/val2);
                    break;
                }
            }
            i++;    
        } else {
            i++;
        }
    }
    return pop(stack);
}

int main () {
    int res = postfixEval("34 54 6 + *");
    printf("res = %d \n", res);
    return 0;
}
