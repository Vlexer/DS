#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Queue
{
    /* data */
    int size;

    int front;
    int rear;
    int * q;

} Queue;
 
void createQueue ( Queue *q, int size ) {
    q->front = 0;
    q->rear = 0;
    q->size = size;
    q->q = ( int * ) malloc ( sizeof(int) * q->size );
}

bool isFull ( Queue * q ) {
    if ( (q->rear+1) % q->size == q->front ) {
        return true;
    } else return false;
}
bool isEmpty ( Queue * q ) {
    if ( q->front == q->rear ) return true;
    else return false;
}
void Enqueue ( Queue * q, int x ) {
    if ( isFull( q ) ) printf("Queue is full\n");
    else {
        q->rear = ( q->rear + 1 ) % q->size;
        q->q[q->rear] = x;
    }
}
int Dequeue ( Queue * q ) {
    if ( isEmpty( q ) ) { printf("Queue is empty \n"); return -1;}
    else {
        q->front = ( q->front + 1 ) % q->size;
        return q->q[ q->front ];
    }
}
int peek ( Queue * q ) {
    if ( isEmpty( q ) ) { printf("Queue is empty \n"); return -1;}
    else {
        
        return q->q[ (q->front + 1) % q->size ];
    } 
}

void main() {
    Queue q;
    printf("Enter the Size of the queue\n");
    int size;
    scanf("%d",&size);
    createQueue(&q, size);
    printf("Enter 1 to Enqueue 2 to Dequeue 3 to Peek\n");
    int choice;
    scanf("%d",&choice);
    while ( choice != 4 ) {
        switch ( choice )
        {
        case 1: {
            printf("Enter the element to be enqueued\n");
            int x;
            scanf("%d",&x);
            Enqueue(&q, x);break;
        } case 2: {
            int x = Dequeue(&q);
            if ( x != -1 )
                printf(" Dequeued element is %d\n",x);
            
            break;
        } case 3:
        {   
            if (peek(&q) != -1)
            printf("Head of the queue is %d\n",peek(&q));
        }
        
        default:
            break;
        }
        printf("\nEnter 1 to Enqueue 2 to Dequeue 3 to Peek");
        scanf("%d",&choice);
    }

}