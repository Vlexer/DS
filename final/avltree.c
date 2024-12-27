#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
} node;

node * createNode ( int x ) {
    node * temp = ( node * ) malloc ( sizeof(node) );
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
    return (getHeight(T->left) - getHeight(T->right));
}

int max ( int x, int y ) 
{
    return x > y ? x : y;
}

void updateHeight ( node * T ) {
    T->height = 1 + max ( getHeight(T->left), getHeight(T->right) );
}

node * RightRotate ( node * x ) {
    node * y = x->left;
    node * T2 = y->right;

    y->right = x;
    x->left = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

node * LeftRotate ( node * y ) {
    node * x = y->right;
    node * T2 = x->left;

    x->left = y;
    y->right = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

node * insert ( node * root, int key ) {
    if ( root == NULL ) return createNode(key);
    if ( key < root->data ) root->left = insert(root->left, key);
    else if ( key > root->data ) root->right =  insert ( root->right, key );
    updateHeight(root);
    int balance = getBalanceFactor(root);
    if ( balance > 1 && key < root->left->data ) return RightRotate(root);
    if ( balance > 1 && key > root->left->data ) {
        root->left = LeftRotate( root->left );
        return RightRotate(root);
    }
    if( balance < -1 && key > root->right->data ) return LeftRotate(root);
    if ( balance < -1 && key < root->right->data ) {
        root->right = RightRotate(root->right);
        return LeftRotate (root);
    }
    return root;
}

node * delete ( node * root, int key ) {
    if ( root == NULL ) return NULL;
    if ( key < root->data ) root->left = delete(root->left, key);
    else if ( key > root->data ) root->right = delete(root->right, key);
    else{
        if ( root->left == NULL || root->right == NULL ) {
            node * temp = root->left != NULL ? root->left : root->right;
            if ( temp == NULL ) {
                root = NULL;
            } else {
                *root = *temp;
            }
        } else {
            node * temp = root->right;
            while ( temp->left != NULL ) temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, root->data);
        }
    }
    if ( root == NULL ) return NULL;
    updateHeight(root);
    int balance = getBalanceFactor(root);
    if ( balance > 1 && getBalanceFactor(root->left) >= 0 ) return RightRotate(root);
    if ( balance > 1 && getBalanceFactor(root->left) < 0 ) {
        root->left = LeftRotate(root->left);
        return RightRotate(root); 
    }
    if ( balance < -1 && getBalanceFactor(root->right) <= 0 ) return LeftRotate(root);
    if ( balance < -1 && getBalanceFactor(root->right) > 0 ) {
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}

void sumOddEven ( node * root, int * oddSum, int * evenSum ) {
    
    if ( root != NULL ) {
        sumOddEven(root->left, oddSum, evenSum);
        if ( root->data % 2 == 0 ) *evenSum += root->data;
        else *oddSum += root->data;
        sumOddEven(root->right, oddSum, evenSum);
    }   
}

void findKthOddElement(node *root, int *k) {
    if (root != NULL && *k > 0) { 
        findKthOddElement(root->left, k); 
        
        if (root->data % 2 != 0) { 
            *k = *k - 1; 
            
            if (*k == 0) {
                printf("The %dth odd element is %d\n", *k, root->data);
                return; 
            }
        }
        
        findKthOddElement(root->right, k);
    }
}

int kthOdd ( node * root, int *k ) {
    if ( root == NULL ) return -1;
    int leftResult = kthOdd(root->left, k);
    if ( *k == 0 ) return leftResult;

    if ( root->data % 2 != 0 ) {
        *k = *k - 1;
        if ( *k == 0 ) return root->data;
    }
    return kthOdd(root->right, k);
}

int getInt ( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}
void inorder ( node * T ){
    if ( T != NULL ) {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

int main () {
    int ch;
    node * root = NULL;
    
    ch = getInt("Enter 1 to insert 2 to delete 3 to sum 4 to display 5to kth odd");
    while ( 1 ){
        switch ( ch ) {
            case 1:{
                int x = getInt("Enter the numner");
                root = insert(root, x);
                break;
            } case 2:{
                int x = getInt("Enter the number to delete");
                root = delete(root, x);
                break;
            } case 3:{
                int oddSum = 0, evenSum = 0;
                sumOddEven(root, &oddSum, &evenSum);
                printf("Odd sum = %d and even sum = %d \n", oddSum, evenSum);
                break;
            } case 4:{
                inorder(root);
                break;
            } case 5:{
                int x = getInt("Enter k\n");
                findKthOddElement(root, &x);
                break;
            }
        }
        ch = getInt("Enter 1 to insert 2 to delete 3 to sum 4 to display");
    }
    return 0;
}