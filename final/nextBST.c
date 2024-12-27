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
    else return root;
}

Node * findMin ( Node * root ) {
    if ( root == NULL ) return NULL;
    Node * cur = root;
    while ( cur->left != NULL ) {
        cur = cur->left;
    }
    return cur;
}

Node * delete ( Node * root, int key ) {
    if ( root == NULL ) return root;
    if ( key < root->data ) root->left = delete(root->left, key);
    else if ( key > root->data ) root->right = delete(root->right, key);
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
    return root;
}

Node * inorderSuccessor ( Node * root, int target ) {
    Node * succ = NULL;
    Node * cur = root;
    while ( cur != NULL ) {
        if ( target >= cur->data ) {
            cur = cur->right;
        } else {
            succ = cur;
            cur = cur->left;
        }
    }
    return succ;
}


int getInt ( char *s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}

void inorder ( Node * root ) {
    if ( root != NULL ) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

Node * pred ( Node * root, int target ) 
{
    Node * pred = NULL;
    Node * cur = root;
    while ( cur != NULL ) {
        if ( target <= cur->data ) cur = cur->left;
        else {
            pred = cur;
            cur = cur->right;
        }
    }
    return pred;
}

int leaves ( Node * root ) {
    if ( root == NULL ) return 0;
    if ( root->left == NULL && root->right == NULL ) return 1;
    return leaves(root->left) + leaves(root->right);
} 



int main () {
    int ch = 0;
    Node * root = NULL;
    ch = getInt("Enter 1 to insert 2 to delete 3 to find inorder succ\n");
    while ( 1 ) {
        switch (ch) {
            case 1:{
                int x = getInt("Enter the number to insert");
                root = insert(root, x);
                break;
            } case 2:{
                int x= getInt("Enter the number to delete");
                root = delete(root, x);
                break;
            } case 3:{
                int x = getInt("enter the number");
                Node * succ = pred(root, x);
                printf("Succ is %d\n", succ->data);
            } case 4:{
                inorder(root);
                break;
            }
        }
        ch = getInt("Enter 1 to insert 2 to delete 3 to find inorder succ\n");
    }
    return 0;
}
