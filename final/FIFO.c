#include<stdio.h>
#include<stdlib.h>

typedef struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int TAT;
    int waitime;
    int remTime;
} Process;

typedef struct Queue {
    Process ** pQ;
    int front;
    int rear;
    int c;
    int size;
} Queue;

Queue * queueInit (int nProcess) {
    Queue * temp = ( Queue * )malloc( sizeof(Queue) );
    temp->pQ = ( Process ** )malloc( sizeof(Process *) * nProcess );
    temp->front = 0;
    temp->rear = 0;
    temp->c = 0;
    temp->size = nProcess;
    return temp;
}

void Enqueue(Queue * q, Process * p){
    if ( q->c == q->size ) {
        printf("Queue is full\n");
        return;
    }
    q->pQ[q->rear] = p;
    q->rear = ( q->rear + 1 ) % q->size;
    q->c++;
}

Process * Dequeue( Queue *q ) {
    if ( q->c == 0 ) {
        printf("Queue is empty\n");
        return NULL;
    }
    Process *del = q->pQ[q->front];
    q->front = (q->front + 1) % q->size;
    q->c--;
    return del;
}

int getInt ( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}
typedef struct ProcessList {
    Process ** processes;
    int size;
} ProcessList;

ProcessList * createProcessList () {
    int nProcess = getInt("Enter number of proceses\n");
    ProcessList * temp = ( ProcessList * )malloc ( sizeof(ProcessList) );
    temp->processes = ( Process ** )malloc ( sizeof(Process *) * nProcess );
    for ( int i = 0 ; i < nProcess; i++ ) {
        temp->processes[i] = ( Process * )malloc ( sizeof(Process) );
    }
    temp->size = nProcess;
    for ( int i = 0; i < nProcess; i++ ) {
        printf("Process %d\n", i+1);
        temp->processes[i]->pid = i+1;
        temp->processes[i]->arrivalTime = getInt("enter the arrival time");
        temp->processes[i]->burstTime = getInt("Enter the burst time");
        temp->processes[i]->remTime = temp->processes[i]->burstTime;
    }
    return temp;
}

void printDetails ( Process * p ) {
    printf("Process : Burst Time = %d \t Turn around Time = %d\t Waiting time  = %d\n", p->burstTime, p->TAT, p->waitime);
}

void roundRobin ( ProcessList * list, int timeQuantum ) {
    int time = 0;
    Queue * q = queueInit(list->size);
    for ( int i = 0; i < list->size ; i++ ) {
        Process * cur = list->processes[i];
        Enqueue(q, cur);
    }
    int nProcessComplete = 0;
    while ( nProcessComplete < list->size ) {
        Process * cur = Dequeue(q);
        if ( cur->remTime > timeQuantum ) {
            time += timeQuantum;
            cur->remTime -= timeQuantum;
            printf("Time : %d -> Process : %d\n", time, cur->pid);
            Enqueue(q, cur);
        } else if ( cur->remTime <= timeQuantum ) {
            time += cur->remTime;
            nProcessComplete++;
            cur->TAT = time;
            cur->waitime = cur->TAT - cur->burstTime;
            printDetails(cur);
        }
    }
}

int main () {
    ProcessList * list = createProcessList();
    roundRobin(list, 2);
}