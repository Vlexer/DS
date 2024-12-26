#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    char value;
    struct node_t * left;
    struct node_t * right;
} node_t;

node_t * createNode ( char value ) {
    node_t * temp = ( node_t * )malloc(sizeof(node_t));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
}

int isOperator ( char value ) {
    return ( value == '+' || value == '-' || value == '*' || value == '/' );
}
node_t * buildtree ( char * postfix ) {
    node_t * Stack [ 100 ];
    int top = -1;
    int i = 0;
    while ( postfix[i] != '\0' ) {
        char ch = postfix[i];
        if ( isOperator(ch) ) {
            node_t * newNode = createNode(ch);
            newNode->left = Stack[top--];
            newNode->right = Stack[top--];
            Stack[++top] = newNode;
        } else {
            
            Stack[++top] = createNode(ch);
        }
        i++;
    }
    return Stack[top];
}
int evaluate ( node_t * root ) {
    if ( root == NULL ) return -1;
    if ( !(isOperator(root->value)) ) return (int)(root->value - '0');
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    switch ( root->value ) {
        case '+': return left + right;
        case '-': return left - right;
        case '*':return left * right;
        case '/': return left/right;
    }
    return 0;
} 
int main () 
{
    char exp[] = "234*-";
    node_t *root = buildtree(exp);
    printf("res = %d", evaluate(root));
    return 0;
}