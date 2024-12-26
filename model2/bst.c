#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    int data;
    struct node_t * left;
    struct node_t * right;
} node_t;

node_t * createNode ( int data ) {
    node_t * temp = ( node_t * )malloc( sizeof(node_t) );
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node_t * insert( node_t *root, int key ) {
    if ( root == NULL ) return createNode(key);
    if ( root->data < key ) root->right = insert(root->right, key);
    else if ( root->data > key ) root->left = insert(root->left, key);
    return root;
}

node_t * findMax ( node_t *root ) {
    if ( root->right == NULL ) return root;
    return findMax(root->right);
}

node_t * delete ( node_t * root, int key ) {
    if ( root == NULL )return NULL;
    if ( root->data > key ) root->left = delete(root->left, key);
    else if ( root->data < key ) root->right = delete(root->right, key);
    else {
        if ( root->left == NULL || root->right == NULL ) {
            node_t * temp = ( root->left != NULL ) ? root->left : root->right;
            if ( temp == NULL ) {
                root = NULL;
            } else {
                *root = *temp;
            }
        } else {
            node_t * temp = findMax(root->left);
            root->data = temp->data;
            root->left = delete(root->left, temp->data);
        }
    }   
    return root;
}

node_t * Search ( node_t * root, int key ) {
    if ( root == NULL || root->data == key ) return root;
    if ( key < root->data ) return Search(root->left, key);
    else return Search(root->right, key);
}

void inorder ( node_t * root ) {
    if ( root != NULL ) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    } 
}

int getInt ( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}

int main () {
    int ch = getInt("Enter 1 to Create 2 to Insert 3 to Delete 4 to Search 5 to print ");
    node_t * root = NULL; int isTreeCreated = 0;
    while ( 1 ) {
        switch (ch) {
            case 1:{
                root = NULL;
                printf("New tree created\n");
                isTreeCreated = 1;
                break;
            }
            case 2:{
                if ( !isTreeCreated ) {
                    printf("Create a root first\n");
                    break;
                }
                int x = getInt("Enter the element to insert ");
                root = insert(root, x);
                break;
            }
            case 3:{
                int y = getInt("Enter the element to delete");
                root = delete(root, y);
                break;
            }
            case 4: {
                if ( root == NULL ) {
                    printf("Tree is empty\n");
                    break;
                }
                int x = getInt("Enter the element to Seartch");
                if ( Search(root,x ) != NULL ) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");

                }
                break;
            }
            case 5:{
                inorder(root);
                printf("\n");
                break;
            }
        }
        ch = getInt("Enter 1 to Create 2 to Insert 3 to Delete 4 to Search 5 to print ");
    }
}