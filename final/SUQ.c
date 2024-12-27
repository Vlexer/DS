#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int * array;
    int size;
    int front;
    int rear;
    int c;
} Queue;

Queue * QueueInit ( int size ) {
    Queue * temp = ( Queue * )malloc ( sizeof(Queue) );
    temp->array = ( int * )malloc ( sizeof(int) * size );
    temp->c = 0;
    temp->front = 0;
    temp->rear = 0;
    temp->size = size;
    return temp;
}

void Enqueue( Queue * q, int x ) {
    if ( q->c == q->size ) {
        printf("Queue is full\n"); return;
    }
    q->array[q->rear] = x;
    q->rear = ( q->rear + 1 ) % q->size;
    q->c++;
}
#define ERRCODE -1232
int Dequeue ( Queue * q ) {
    if ( q->c == 0 ) {
        printf("Queue is Empty\n");
        return ERRCODE;
    }
    int del = q->array[q->front];
    q->front = (q->front + 1) % q->size;
    q->c -= 1;
    return del;
}

typedef struct Stack {
    Queue * q;
    int size;
} Stack;

Stack * StackInit( int size ) {
    Stack * temp = ( Stack * )malloc ( sizeof(Stack) );
    temp->q = QueueInit(size);
    temp->size = size;
    return temp;
}

void Push ( Stack * s, int x ) {
    if ( s->q->c == s->size ) return;
    Enqueue(s->q, x);
}

int pop ( Stack * s ) {
    if ( s->q->c == 0 ) {
        printf("Stack is empty\n");
        return ERRCODE;
    }
    int nDequeues = s->q->c - 1;
    int i = 0;
    while ( i < nDequeues ) {
        int temp = Dequeue(s->q);
        Enqueue(s->q, temp);
        i++;
    }
    int del = Dequeue(s->q);
    return del;
}



int main () {
    Stack * s = StackInit(10);
    Push(s, 10);
    Push(s, 20);
    Push(s, 30);
    Push(s, 40);
    printf("%d ", pop(s));
    printf("%d ", pop(s));
    printf("%d ", pop(s));
    printf("%d ", pop(s));

    return 0;
}