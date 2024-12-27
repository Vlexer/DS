#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
} node;

typedef struct Deque {
    node * front;
    node * rear;
} Deque;

node * createNode ( int x ) {
    node * temp = ( node * )malloc ( sizeof(node) );
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
Deque * DequeInit () {
    Deque * temp = ( Deque * )malloc ( sizeof(Deque) );
    temp->front = NULL;
    temp->rear = NULL;
    return temp; 
}

void insertFront ( Deque * d, int x ) {
    if ( d->front == NULL && d->rear == NULL ) {
        node * temp = createNode(x);
        d->front = temp;
        d->rear = temp;
        return;
    }
    node * temp = createNode(x);
    temp->next = d->front;
    temp->prev = NULL;
    d->front->prev = temp;
    d->front = temp;
}

void insertRear ( Deque *d, int x ) {
    if ( d->front == NULL && d->rear == NULL ) {
        node * temp = createNode(x);
        d->front = temp;
        d->rear = temp;
        return;
    }
    node * temp = createNode(x);
    temp->next = NULL;
    temp->prev = d->rear;
    d->rear->next = temp;
    d->rear = temp;
}

node * deleteRear ( Deque *d) {
    if ( d->front == NULL ) return NULL;
    if ( d->front == d->rear ) {
        node * temp = d->front;
        d->front = NULL;
        d->rear = NULL;
        return temp;
    }
    node * del = d->rear;
    d->rear = d->rear->prev;
    d->rear->next = NULL;
    return del;
}

node * deleteFront ( Deque * d) {
    if ( d->front == NULL ) return NULL;
    if ( d->front == d->rear ) {
        node * temp = d->front;
        d->front = NULL;
        d->rear = NULL;
        return temp;
    }
    node * del = d->front;
    d->front = d->front->next;
    d->front->prev = NULL;
    return del;
}

int getInt ( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}

void printDeque (Deque * d) {
    node * cur = d->front;
    while ( cur != NULL ) {
        printf("%d => ", cur->data);
        cur = cur->next;
    }
}

int main ()  {
    Deque * d = DequeInit();
    int ch;
    ch = getInt("Enter 1 to insert front 2 to insert rear 3 to delete front and 4 to delete rear\n");
    while ( 1 ) {
        switch ( ch ) {
            case 1: {
                int x = getInt("enter the number to insert at front\n");
                insertFront(d,x);
                printDeque(d);
                break;
            } case 2:{
                int x = getInt("Enter the nunmber");
                insertRear(d,x);
                printDeque(d);
                break;
            } case 3:{
                if ( d->front == NULL ) {
                    printf("Deque is empty\n");
                    break;
                }
                node * temp = deleteFront(d);
                printf("Deleted node is %d\n", temp->data);
                printDeque(d);
                break;
            } case 4:{
                if ( d->front == NULL ) {
                    printf("Deque is empty\n");
                    break;
                }
                node * temp = deleteRear(d);
                printf("Deleted node is %d\n", temp->data);
                printDeque(d);
            }
             
        }
        ch = getInt("Enter 1 to insert front 2 to insert rear 3 to delete front and 4 to delete rear\n");
    }
}