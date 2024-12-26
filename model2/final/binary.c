#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
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

node_t * Search ( node_t * root, int x ) {
    if ( root == NULL ) return NULL;
    if ( root->data == x ) return root;
    node_t * left = Search(root->left, x);
    node_t * right = Search(root->right, x);
    if ( left != NULL ) return left;
    return right; 
}

void insert ( node_t ** root, int data, int parent, char ch ) {
    if ( *root == NULL ) {
        *root = createNode(data);
        return;
    }
    node_t * par = Search(*root, parent);
    if ( par == NULL ) {
        printf("node doesn not eexist\n");
        return;
    }
    if ( ch == 'l' ) {
        if ( par->left != NULL ) {
            printf("node already exist\n");
            return;
        } 
        par->left = createNode(data);
    } else if ( ch == 'r' ) {
        if ( par->right == NULL ) par->right = createNode(data);
        else printf("Node already exists\n");
    } else printf("Invalid input");
}

bool isBST ( node_t * root, int min ,int max ) {
    if ( root == NULL )return true;
    if ( root->data >= max || root->data <= min ) return false;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}
int max ( int x, int y ) {
    return x > y ? x : y;
}
int getHeight ( node_t * root ) {
    if ( root == NULL )return -1;
    int leftheight= getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1  + max( leftheight, rightHeight );
}
bool isAVL ( node_t * root ) {
    if ( root == NULL )return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if ( abs(leftHeight - rightHeight) > 1 ) return false;
    return  isBST(root, 100000, -1000000) && isAVL(root->left) && isAVL(root->right);
}

int getNPL ( node_t * root ) {
    if ( root == NULL )return -1;
    int leftNPL = getNPL(root->left);
    int rightNPL = getNPL(root->right);
    return 1 + ( leftNPL < rightNPL ? leftNPL : rightNPL );
}

bool isLeftisit ( node_t * root ) {
    if ( root == NULL )return true;
    int leftNPL = getNPL(root->left);
    int rightNPL = getNPL(root->right);
    if ( rightNPL > leftNPL ) return false;
    if( ( root->left && root->data > root->left->data  ) || (root->right && root->data > root->right->data) ) return false;
    return isLeftisit(root->left) && isLeftisit(root->right);
}


node_t * LCA ( node_t * root, int p, int q ) {
    if ( root == NULL ) return NULL;
    if ( root->data == p || root->data == q ) return root;
    node_t * leftCLA = LCA(root->left , p ,q);
    node_t * rightLCA = LCA ( root->right, p, q );
    if ( leftCLA != NULL  && rightLCA != NULL ) return root;
    return leftCLA != NULL ? leftCLA : rightLCA;
}

int findPathDistance ( node_t * root, int target, int * path, int * dist, int level ) {
    if ( root == NULL ) return 0;
    path[*dist] = root->data;
    (*dist)++;

    if ( root->data == target ) return 1;

    if ( findPathDistance(root->left, target, path, dist, level + 1) || findPathDistance(root->right, target,path, dist, level + 1) ) return 1;
    (*dist)--;
    return 0;
}

void printPath ( int * path, int dist ) 
{
    for( int i = 0;i < dist; i++ ) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void mainFindPath ( node_t * root, int target ) {
    int path[1000];
    int dist = 0;

    int found = findPathDistance(root, target, path, &dist, 0);
    if ( found ) {
        printPath(path, dist);

    } else {
        printf("Node doesnt found\n");
    }
}

bool isFull( node_t * root ) {
    if ( root == NULL ) return true;
    if ( root->left == NULL && root->right == NULL ) return true;
    if ( root->left != NULL && root->right != NULL ) return isFull(root->left) && isFull(root->right);
    return false;
}

typedef struct Queue {
    int front;
    int size;
    int rear;
    node_t ** array;
    int c;
} Queue;

Queue * QueueInit ( int size ) {
    Queue * temp = ( Queue * )malloc ( sizeof(Queue) );
    temp->array = ( node_t ** )malloc( sizeof(node_t) * size );
    temp->front = 0;
    temp->rear = 0;
    temp->size = size;
    temp->c = 0;
    return temp;
}

void Enqueue ( Queue * q, node_t * node ) {
    q->array[q->rear] = node;
    q->rear = ( q->rear + 1 ) % q->size;
    q->c++;
}

node_t * Dequeue ( Queue * q ) {
    node_t * temp = q->array[q->front];
    q->front = ( q->front + 1 ) % q->size;
    q->c--;
    return temp;
}

bool isComplete ( node_t * root ) {
    Queue * q = QueueInit(1000);
    Enqueue(q, root);
    int flag = 0;
    while ( q->c != 0 ) {
        node_t * node = Dequeue(q);
        if ( node == NULL ) flag = 1;
        else {
            if ( flag == 1 ) return false;
            Enqueue(q,node->left);
            Enqueue(q, node->right);
        }
    }
    return 1;
}

bool isSametree( node_t * root1, node_t * root2) {
    if ( root1 == NULL && root2 == NULL )return true;
    if ( root1 == NULL && root2 != NULL ) return false;
    if ( root1 != NULL && root2 == NULL ) return true;
    if ( root1->data == root2->data ) return isSametree(root1->left, root2->left) && isSametree(root1->right, root2->right);
    return false;
}

bool isSubTree ( node_t * t1, node_t * t2 ) {
    if ( t2 == NULL ) return true;
    if ( t1 == NULL ) return false;
    if ( isSametree(t1, t2) ) return true;
    return isSubTree(t1->right, t2->right) || isSubTree(t1->left, t2->left);
}

node_t * mirror ( node_t * root ) {
    if ( root == NULL ) return NULL;
    node_t * left = mirror(root->left);
    node_t * right = mirror(root->right);

    root->left = right;
    root->right = left;
}

bool isIsomorphic ( node_t * T1, node_t * T2 ) {
    if ( T1 == NULL && T2 == NULL ) return true;
    if ( T1 == NULL || T2 == NULL ) return false;
    if ( T1->data != T2->data ) return false;

    bool a = isIsomorphic(T1->left, T2->left) && isIsomorphic(T1->right, T2->right);
    bool b = isIsomorphic(T1->left, T2->right) && isIsomorphic(T1->right, T2->left);
    return a || b;
}



int main() {
    // Create a binary tree
    node_t* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Find the shortest path and distance from root to a given node
    printf("is it complete = %d", isComplete(root));
    return 0;
}