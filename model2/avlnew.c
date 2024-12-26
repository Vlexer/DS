#include<stdio.h>
#include<stdlib.h>
typedef struct node_t {
    int x;
    struct node_t * left;
    struct node_t * right;
    int height;
} node_t;
node_t * createNode ( int x ) {
    node_t * temp = malloc( sizeof(node_t) );
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    temp->x = x;
    return temp;
}
int max ( int x, int y ) {
    return ( x > y) ? x : y;
}
int getHeight( node_t * node ) {
    if ( node == NULL ) return -1;
    return node->height;
} 
int getBalanceFactor( node_t * node ) {
    if ( node == NULL ) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
void updateHeight ( node_t * node )  {
    if ( node == NULL ) return;
    node->height = max ( getHeight(node->left), getHeight(node->right) ) + 1;
}
node_t * rightRotate ( node_t * y ) {
    node_t *x = y->left;
    node_t * T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}
node_t * leftRotate( node_t * x ) {
    node_t *y = x->right;
    node_t * T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}
node_t * insert ( node_t * node, int x ) {
    if ( node == NULL ) return createNode(x);
    if ( x > node->x ) node->right = insert(node->right, x );
    if ( x < node->x ) node->left = insert(node->left,x);
    else return node;
    updateHeight(node);
    int balance = getBalanceFactor(node);
    if ( balance > 1 && x < node->left->x ) return rightRotate(node);
    if ( balance > 1 && x > node->left->x )  {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if ( balance < -1 && x > node->right->x ) return leftRotate(node);
    if ( balance < -1 && x < node->right->x ) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
node_t * maxNode ( node_t * node ) {
    if ( node->right == NULL ) return node;
    return maxNode ( node->right );
}
node_t * delete ( node_t * root, int x ) {
    if ( root == NULL ) return root;
    if ( x > root->x ) root->right = delete(root->right, x);
    if ( x < root->x ) root->left = delete(root->left, x);
    else {
        if ( root->left == NULL || root->right == NULL ) {
            node_t * temp = ( root->left != NULL ) ? root->left : root->right;
            if( temp == NULL ) {
                root = NULL;
            } else {
                *root = *temp;
            }
        } else {
            node_t * max = maxNode(root->left);
            root->x = max->x;
            root->left = delete(root->left, max->x);
        }
    }
    if ( root == NULL ) return NULL;
    updateHeight(root);
    int balance = getBalanceFactor(root);
    if ( balance > 1 && getBalanceFactor(root->left) >= 0 ) return rightRotate(root);
    if ( balance > 1 && getBalanceFactor(root->left) < 0 ) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if ( balance < -1 && getBalanceFactor(root->right) <= 0 ) return leftRotate(root);
    if ( balance < -1 && getBalanceFactor(root->right) > 0 ) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
} 

void main () {
    
}