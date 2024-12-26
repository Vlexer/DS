#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Queue {
    int front;
    int rear;
    int * Q;
    int size;
} Queue;

void createQueue ( Queue *q, int size ) {
    q->size = size;
    q->front = -1; q->rear = -1;
    q->Q = ( int * ) malloc(sizeof(int) * size);
}
bool isFull( Queue * q ) {
    if ( q->rear == q->size ) return true;
    else return false;
}
bool isEmpty ( Queue * q ) {
    if ( q->front == q->rear ) return true;
    else return false;

}
void Enqueue ( Queue *q , int x) {
    if ( !isFull( q ) ) {
        q->rear++;
        q->Q[q->rear] = x;
    } else {
        printf("Queue is Full\n");
    }
} 
int Dequeue ( Queue * q ) {
    if ( !isEmpty( q ) ) {
        q->front++;
        return q->Q[q->front];
    } else {
        printf("QUeue is Empty!!\n");
    }
}
void printQueue ( Queue * q ) {
    printf("The Queue is \n");
    if ( !isEmpty(q) ) {
        int start = ( q->front == -1 ) ? 0 : q->front + 1;
        
        for ( int i = start; i <= q->rear; i ++ ) {
        printf("%d ",q->Q[i]);
    }
    }
    printf("\n\n");
} 
void main() {
    Queue q;
    int size = 3;
    createQueue( &q , size );
    Enqueue ( &q, 10 );
    printQueue( &q );
    Enqueue ( &q, 20 );
    printQueue( &q );
    Enqueue ( &q, 30 );
    printQueue( &q );
    Dequeue( &q );
    printQueue( &q );
    Enqueue ( &q, 30 );
    printQueue( &q );Enqueue ( &q, 30 );
    printQueue( &q );
    Dequeue( &q );
    printQueue( &q );
    Dequeue( &q );
    printQueue( &q );
    Dequeue( &q );
    printQueue( &q );
    Dequeue( &q );
    printQueue( &q );
}