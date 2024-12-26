#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    int x;
    struct node_t * left;
    struct node_t * right;
    int height;
} node_t;

node_t * createNode( int x ) {
    node_t * temp = ( node_t * )malloc( sizeof(node_t) );
    temp->height = 0;
    temp->x = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int max ( int x, int y ) {
    return ( x > y ) ? x : y;
}
int height ( node_t * node ) {
    if ( node == NULL ) return -1;
    return node->height;
}
int getBalanceFactor( node_t * node ) {
    if ( node == NULL ) return 0;
    return height(node->left) - height(node->right);
}

void updateHeight ( node_t * node ) {
    if ( node != NULL ) {
        node->height = max ( height(node->left), height(node->right) ) + 1;
    }
}

node_t * rightRotate ( node_t * y ) {
    node_t * x = y->left;
    node_t * T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

node_t * leftRotate ( node_t * x ) {
    node_t * y = x->right;
    node_t * T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

node_t * insert ( node_t * node, int x ) {
    if ( node == NULL ) return createNode(x);
    if ( x < node->x ) node->left = insert(node->left, x);
    if ( x > node->x ) node->right = insert( node->right, x);
    else return node;
    updateHeight(node);
    int balance = getBalanceFactor(node);
    if ( balance > 1 && x < node->left->x ) return rightRotate(node);
    if ( balance > 1 && x > node->left->x ) {
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

node_t * maxNode ( node_t * t ) {
    if ( t->right == NULL ) return t;
    return maxNode(t->right);
}

node_t * delete ( node_t * node, int x ) {
    if ( node == NULL ) return node;
    if ( x > node->x ) node->right = delete( node->right, x );
    if ( x < node->x )  node->left = delete(node->left, x);
    else {
        if ( node->left == NULL || node->right == NULL ) {
            node_t * temp = ( node->left != NULL ) ? node->left : node->right;
            if ( temp == NULL ) {
                // dealing with zero child case 
                node = NULL;
            } else {
                // dealing with one child case 
                *node = *temp;
            }
        } else {
            node_t * temp = maxNode(node->left);
            node->x = temp->x;
            node->left = delete(node->left, node->x);
        }
    }
    if ( node == NULL ) {
        return NULL;
    }
    updateHeight(node);
    int balance = getBalanceFactor(node);
    if ( balance > 1 && getBalanceFactor(node->left) >= 0 ) return rightRotate(node);
    if ( balance > 1 && getBalanceFactor(node->left) < 0 ) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if ( balance < -1 && getBalanceFactor(node->right) <= 0 ) return leftRotate(node);
    if ( balance < -1 && getBalanceFactor(node->right) > 0 ) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int main () {
    
}