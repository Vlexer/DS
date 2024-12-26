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

node_t * buildTree ( char *postfix ) {
    node_t * Stack[100];
    int top = -1;
    for ( int i = 0; postfix[i] != '\0'; i++ ) {
        char ch = postfix[i];
        if (  isOperator(ch)  ){
            node_t * node = createNode(ch);
            node->left = Stack[top--];
            node->right = Stack[top--];
            Stack[++top] = node;
        } else {
            Stack[++top] = createNode(ch);
        }
    }
    return Stack[top];
}

void printInfix ( node_t * root ) {
    if ( root == NULL ) return;
    if ( root->left != NULL && root->right != NULL ) {
        printf("(");
    }
    printInfix(root->left);
    printf("%c ",root->value);
    printInfix(root->right);
    if ( root->left != NULL && root->right != NULL ) {
        printf(")");
    }
}

int evaluate ( node_t * root ) {
    if ( root == NULL ) {
        return 0;
    }
    if ( !isOperator(root->value) ) 
    {
        return (int)(root->value - '0');
    }
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    switch ( root->value ) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left/right;
    }
    return 0;
}

int main () {
    char s[] = "23*5+";
    node_t * root = buildTree(s);
    printInfix(root);
    printf("result : %d", evaluate(root));
}