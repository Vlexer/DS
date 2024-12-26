#include<stdio.h>
#include<stdlib.h>

typedef struct Process {
    int id;
    int arrivalTime;
    int BurstTime;
    int remainingTime;
    int turnAroundTime;
    int waitTime;
    int completionTime;
    struct Process * next;

} Process;

Process * createProcess ( int id, int arrivalTime, int burstTime  ) {
    Process * p = ( Process * ) malloc(sizeof(Process) );
    p->arrivalTime = arrivalTime;
    p->BurstTime = burstTime;
    p->id = id;
    p->completionTime = 0;
    p->remainingTime = burstTime;
    p->waitTime = 0;
    p->turnAroundTime = 0;
    p->next = p;
    return p;
}


void addProcess ( int id, int arrivalTime, int burstTime, Process ** head ) {
    
    Process * p = createProcess(id, arrivalTime, burstTime);
    if ( *head == NULL ) {
        *head = p;
    } else {
        Process *temp = *head;
        while ( temp->next != *head ) {
            temp = temp->next;
        }   
        temp->next = p;
        p->next = *head;
    }

}

void RoundRobin ( Process * head, int timeQuantum ) {
    int completedTask = 0;
    int time = 0;
    Process * cur = head;
    int n = 0;
    Process* temp = head;
    do {
        n++;
        temp = temp->next;
    } while (temp != head);


    while ( completedTask < n ) {
        if ( cur->remainingTime > 0 ) {
            if ( cur->remainingTime > timeQuantum ) {
                time += timeQuantum;
                cur->remainingTime -= timeQuantum;
            } else {
                time += cur->remainingTime;
                cur->remainingTime = 0;
                cur->completionTime =time;
                cur->turnAroundTime = cur->completionTime - cur->arrivalTime;
                cur->waitTime = cur->turnAroundTime - cur->BurstTime;
                completedTask++;
            }

        }
        cur = cur->next;
    }
}
void calculateAndDisplayAverages(Process* head) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int numProcesses = 0;
    Process* temp = head;

    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    do {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", temp->id, temp->arrivalTime, temp->BurstTime, temp->completionTime, temp->turnAroundTime, temp->waitTime);
        totalWaitingTime += temp->waitTime;
        totalTurnaroundTime += temp->turnAroundTime;
        numProcesses++;
        temp = temp->next;
    } while (temp != head);

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / numProcesses);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / numProcesses);
}

int main() {
    Process* processList = NULL;

    // Adding processes (id, arrival time, burst time)
    addProcess( 1, 0, 5,&processList);
    addProcess( 2, 1, 4,&processList);
    addProcess( 3, 2, 2,&processList);
    addProcess( 4, 3, 1,&processList);

    int timeQuantum = 2;
    RoundRobin(processList, timeQuantum);
    calculateAndDisplayAverages(processList);

    return 0;
}