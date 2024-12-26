#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    /* data */
    int size;
    int front;
    int rear;
    int * queue;
} Queue;

Queue * createQueue ( int size ) {
    Queue * q = ( Queue * ) malloc( sizeof(Queue) );
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->queue = ( int * ) malloc ( sizeof(int) * size );
    return q;
}

void Enqueue ( Queue *q , int x ) {
    if ( ( q->rear + 1 ) % q->size == q->front ) {
        printf("Queue  is full\n");
    } else {
        int nextIndex = ( q->rear + 1 ) % q->size;
        q->rear = nextIndex;
        q->queue[nextIndex] = x;
    }
}

int Dequeue ( Queue * q ) {
    if ( q->front == q->rear ) {
        printf("the queue is empty!\n");
    } else {
        int frontIndex = ( q->front + 1 ) % q->size;
        int elementToBeDeleted = q->queue[q->front];
        q->front = frontIndex;
        return elementToBeDeleted;
    }
}

void push ( Queue * q1, Queue * q2, int x ) {
    if ( (q1->front + 1) % q1->size == q1->rear ) {
        printf("Stack is full\n");

    } else {
        Enqueue(q1, x);
    }
} 

int pop ( Queue * q1, Queue * q2 ) {
    if ( q1->front == q1->rear ) {
        printf("Stack is empty\n");
        return -2147483648;
    } else 
    {
        while ( ( q1->front + 1 ) % q1->size == q1->rear ) {
            Enqueue(q1, Dequeue(q1));
            q1->front = ( q1->front + 1 ) % q1->size;
        }
        return q1->front;
    }
}

int peek ( Queue * q1, Queue * q2 ) {
    if ( q1->front == q1->rear ) {
        printf("The Stack is empty\n");

        return -2147483648;
    } else {
        return q1->queue[q1->rear];
    }
}

void display ( Queue * q ) {
    for ( int i =  ( q->front == -1 ) ? 0 : q->front; i != q->rear ; i = ( i + 1 ) % q->size ) {
        printf("%d ", q->queue[i]);
    }
}

void main () {
    Queue * q1, *q2;
    q1 = createQueue(3);
    q2 = createQueue(3);
    printf("Enter 1 to push 2 to pop\n");
    int ch;
    scanf("%d",&ch);
    while ( ch != 3 ) {
        switch ( ch ) {
            case 1: {
                printf("enter the element to push\n");
                int x;
                scanf("%d",&x);
                push(q1,q2,x);
                display(q1);
                break;
            } 
            case 2: {
                int poppedElement = pop(q1,q2);
                if ( poppedElement != -2147483648 ) {
                    printf("the popped element = %d\n", poppedElement);
                }
                display(q1);
                break;
            }
            case 3: {
                int peekElement = peek( q1, q2 );
                if ( peekElement != -2147483648 ) {
                    printf("Peek Element = %d\n",peekElement);
                }
                display(q1);
            }
        }
        printf("Enter 1 to push 2 to pop\n");
        scanf("%d",&ch);
    }
}