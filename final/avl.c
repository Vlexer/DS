#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
} node;

node * createNode ( int x ) {
    node * temp = ( node * )malloc ( sizeof(node) );
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 0;
    return temp;
}

int getHeight ( node * N ) {
    if ( N == NULL ) return -1;
    return N->height;
}

int getBalanceFactor( node * T ) {
    if ( T == NULL ) return 0;
    return getHeight(T->left) - getHeight(T->right);
}

int max ( int x, int y ) {
    return x > y ? x : y;
}

void updateHeight ( node * T ) {
    if ( T != NULL ) {
        return 1 + max ( getHeight(T->left), getHeight(T->right) );
    }
}

node * rightRotate( node * x ) {
    node * y = x->left;
    node * T2 = y->right;

    y->right = x;
    x->left = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

node * lefTRotate ( node * x ) {
    node * y = x->left;
    node * T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

node * insert ( node * node, int key ) {
    if ( node == NULL ) return createNode(key);
    if ( key < node->data ) node->left = insert(node->left, key);
    else if ( key > node->data ) node->right = insert(node->right, key);
    updateHeight(node);
    int balance = getBalanceFactor(node);
    if ( balance > 1 && key < node->left->data ) return rightRotate(node);
    if ( balance > 1 && key > node->left->data ) {
        node->left = lefTRotate(node->left);
        return rightRotate(node);
    }
    if ( balance < 1 && key > node->right->data ) return lefTRotate(node);
    if ( balance < 1 && key < node->right->data ) {
        node->right = rightRotate(node->right);
        return lefTRotate(node);
    }
    return node;
}

node * delete( node * Node, int key ) {
    if ( Node == NULL ) return NULL;
    if ( key < Node->data ) Node->left = delete(Node->left, key);
    else if ( key > Node->data ) Node->right = delete(Node->right, key);
    else {
        if ( Node->left == NULL || Node->right == NULL ) {
            node * temp = Node->left != NULL ? Node->left : Node->right;
            if ( temp == NULL ) {
                temp = Node;
                Node = NULL; 
            } else {
                *Node = *temp;
            }
            free(temp);
        } else{
            node  *temp = Node->right;
            while ( temp->left != NULL ) 
                temp = temp->left;
            Node->data = temp->data;
            Node->right = delete(Node->right, temp->data);
        }
    }
    if ( Node == NULL ) {
        return Node; 
    }
    updateHeight(Node);
    int balance = getBalanceFactor(Node);
    if( balance > 1 && getBalanceFactor(Node->left) >= 0 ) return rightRotate(Node);
    if ( balance > 1 && getBalanceFactor(Node->left) < 0 ) {
        Node->left = lefTRotate(Node->left);
        return rightRotate(Node);
    }
    if ( balance < -1 && getBalanceFactor(Node->right) <= 0 ) return lefTRotate(Node);  
    if ( balance < -1 && getBalanceFactor(Node->right) < 0 ) {
        Node->right = rightRotate(Node->right);
        return lefTRotate(Node);
    }
    return Node;
}
