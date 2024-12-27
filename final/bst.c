#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
} Node;

Node * createNode ( int x ) {
    Node * temp = ( Node * )malloc ( sizeof(Node) );
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} 

Node * insert ( Node * root, int key ) {
    if ( root == NULL ) return createNode(key);
    if ( key < root->data ) root->left = insert(root->left, key);
    else if ( key > root->data ) root->right = insert(root->right, key);
    return root;
}
Node * findMin ( Node * root ) {
    while ( root && root->left != NULL ) {
        root = root->left;
    }
    return root;
}
Node * delete( Node * root, int key ) {
    if ( root == NULL ) return NULL;
    if ( key < root->data ) root->left = delete(root->left, key);
    else if ( key > root->data ) root->right = delete(root->right,key);
    else {
        if ( root->left == NULL || root->right == NULL ) {
            Node * temp = root->left != NULL ? root->left : root->right;
            if ( temp == NULL ) {
                root = NULL;
            } else {
                *root = *temp;
            }
        } else {
            Node * temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return  root;
} 
