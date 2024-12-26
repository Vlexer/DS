#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
typedef struct node_t {
    int data;
    struct node_t * left;
    struct node_t * right;
} node_t;

node_t * createNode ( int x ) {
    node_t * temp = ( node_t * )malloc ( sizeof(node_t) );
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node_t * Search ( node_t *root, int key ) {
    if ( root == NULL ) return NULL;
    if ( root->data == key ) return root;
    node_t * left = Search(root->left, key);
    node_t * right = Search(root->right, key);
    return ( left != NULL ) ? left : right;
}

void insert ( node_t ** root, int data, int parent, char lr ) {
    if (*(root) == NULL) {
        
        node_t *temp = createNode(data);
        *(root) = temp;
        return;
    }
    node_t * p = Search(*root,parent);
    if ( p == NULL ) {
        printf("Parent node doesnt exist\n");
        return;
    }
    if ( lr == 'l' ) {
        if ( p->left == NULL ) p->left = createNode(data);
        else printf("Left node already exist\n");
    } else if ( lr == 'r') {
        if ( p->right == NULL ) p->right = createNode(data);
        else printf("Right node doesnt exist\n");
    } else printf("invalid input\n");
}

// bool isBST(node_t* root, int min, int max) {
//     if (root == NULL) return true;
//     if (root->data <= min || root->data >= max) return false;
//     return isBST(root->left, min, root->data) && isBST(root->right, root->data, max); 
// }

// // Function to calculate the height of a node
// int getHeight(node_t* root) {
//     if (root == NULL) return -1;
//     int leftHeight = getHeight(root->left);
//     int rightHeight = getHeight(root->right);
//     return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
// }

// // Check if a tree is AVL (including BST check)
// bool isAVL(node_t* root) {
//     if (root == NULL) return true;

//     // Check height balance
//     int leftHeight = getHeight(root->left);
//     int rightHeight = getHeight(root->right);

//     if (abs(leftHeight - rightHeight) > 1) return false;

//     // Check BST property and recursively check AVL property
//     return isBST(root, -2147483648, 2147483647) && isAVL(root->left) && isAVL(root->right);
// }

// // Print elements in descending order (reverse in-order traversal)
// void printDescending(node_t* root) {
//     if (root == NULL) return;
//     printDescending(root->right);
//     printf("%d ", root->data);
//     printDescending(root->left);
// }

// // Calculate Null Path Length (NPL) for leftist heap
// int getNPL(node_t* root) {
//     if (root == NULL) return -1;
//     int leftNPL = getNPL(root->left);
//     int rightNPL = getNPL(root->right);
//     return 1 + (leftNPL < rightNPL ? leftNPL : rightNPL);
// }

// // Check if a tree is a leftist heap
// bool isLeftistHeap(node_t* root) {
//     if (root == NULL) return true;

//     int leftNPL = getNPL(root->left);
//     int rightNPL = getNPL(root->right);

//     // Check heap property (min-heap in this case)
//     if ((root->left && root->left->data < root->data) || (root->right && root->right->data < root->data)) {
//         return false;
//     }

//     // Check leftist property (NPL of left child >= NPL of right child)
//     if (leftNPL < rightNPL) return false;

//     // Recursively check for leftist heap properties in subtrees
//     return isLeftistHeap(root->left) && isLeftistHeap(root->right);
// }

bool isBST ( node_t * root, int max, int min ) {
    if ( root == NULL ) return true;
    if ( root->data >= max || root->data <= min ) return false;
    return isBST(root->left, root->data, min) && isBST(root->right, max, root->data);
}
int getHeight ( node_t * root ) {
    if ( root == NULL ) return -1;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 +   ( ( leftHeight > rightHeight ) ? leftHeight : rightHeight );
}
bool isAVL ( node_t * root ) {
    if ( root == NULL ) return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if ( abs(leftHeight - rightHeight) > 1 ) return false;
    return isBST(root, INT_MAX, INT_MIN) && isAVL(root->left) && isAVL(root->right);
}

int getNPL ( node_t * root ) {
    if ( root == NULL ) return -1;
    int leftNPL = getNPL(root->left);
    int rightNPL = getNPL(root->right);
    return 1 +  ( leftNPL < rightNPL ? leftNPL : rightNPL );
}
bool isLeftist ( node_t *root ) {
    if ( root == NULL ) return true;
    int leftNPL = getNPL(root->left);
    int rightNPL = getNPL(root->right);
    if ( rightNPL > leftNPL ) return false;
    if ( (root->left && root->left->data < root->data) || (root->right && root->right->data < root->data) ) return false;
    return isLeftist(root->left) && isLeftist(root->right);
}

int getInt ( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}
void Inorder ( node_t *root ) {
    if ( root != NULL ) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}
int main () {
    int ch = getInt("Enter 1 to insert 2 to print 3 to check if its AVL 4 to check Leftist Heap\n ");
    node_t * root = NULL;
    while ( 1 ) {
        switch ( ch ) {
            case 1:{
                printf("Enter the element to input\n");
                int data, parent;
                char lr;
                scanf("%d %d %c", &data, &parent, &lr);
                insert(&root, data, parent, lr);
                break;
            } 
            case 2:{
                Inorder(root);
                printf("\n");
            }
            case 3:{
                int height = 0;
                if ( isAVL(root) ) {
                    printf("The tree is AVL\n");
                    printDescending(root);
                } else {
                    printf("NOT AVL\n");
                }
                break;
            }
            case 4:{
                int rank = 0;
                if ( isLeftistHeap(root) ) {
                    printf("Leftist Heap\n");

                } else {
                    printf("NOT LEFtist\n");
                }
                break;
            }
        }
        ch = getInt("Enter 1 to insert 2 to print\n");
    }
    return 0;
}
