#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Queue
{
    /* data */
    int * queue;
    int front;
    int rear;
    int size;
} Queue;

Queue * createQueue ( int size ) {
    Queue * q = ( Queue * )malloc( sizeof(Queue) );
    q->front = q->rear = -1;
    q->size = size;
    q->queue = ( int * ) malloc( sizeof(int) * size );
    return q;
}

bool isFull ( Queue * q ) {
    if ( ( q->rear + 1 ) % q->size == q->front ) return true;
    return false;
}

bool isEmpty ( Queue * q ) {
    if ( q->front == q->rear ) return true;
    return false;
}  

void Enqueue ( Queue * q, int x ) {
    if ( isFull(q) ) printf("Queue is full\n");
    else {
        q->rear = ( q->rear + 1 ) % q->size;
        q->queue [ q->rear ] = x;
    } 
}

int Dequeue ( Queue * q ) {
    if ( isEmpty(q) ) {
        printf("Queue is empty\n");
        return __INT_MAX__;
    } else {
        q->front = ( q->front + 1 ) % q->size;
        return q->queue[q->front];
    }

}

int numberOfElementInQueue(Queue *q) {
    if (isEmpty(q)) return 0;  // Return 0 if the queue is empty

    // If rear is ahead or equal to front (no wrap-around)
    if (q->rear >= q->front) {
        return q->rear - q->front;
    } else {
        // If wrap-around occurs
        return (q->size - q->front) + q->rear;
    }
}


void Push ( Queue * q ) {
    if ( isFull(q) ) {
        printf("Stack is full\n");
    } else {
        printf("enter the element to be pushed\n");
        int x;
        scanf("%d", &x);
        Enqueue(q, x);
    }
} 
int pop ( Queue * q ) {
    if ( isEmpty(q) ) {
        printf("The queue is empty\n");
        return __INT_MAX__;
    } else {
        int l = numberOfElementInQueue(q);
        for( int i = 0 ; i < l -1; i++ ) {
            Enqueue(q, Dequeue(q));
        }
        return Dequeue(q);
    }
}  



void main () {
    int ch;
    int size;
    printf("Enter the size of the Stack\n");
    scanf("%d", &size);
    Queue * q = createQueue(size + 1);
    printf("Enter 1 to push 2 to pop\n");
    scanf("%d", &ch);
    while ( ch != 3 ) {
        switch( ch ) {
            case 1:{
                Push(q);
                break;
            }
            case 2:{
                int x = pop(q);
                if ( x != __INT_MAX__ ) {
                    printf("Popped element is %d\n", x);
                }
            }
        }
        printf("Enter 1 to push 2 to pop\n");
        scanf("%d", &ch);
    }
}