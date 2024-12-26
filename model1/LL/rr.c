#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    struct process* next;
} process_t;

// Function to create a new process node
process_t* createProcess(int id, int arrivalTime, int burstTime) {
    process_t* newProcess = (process_t*)malloc(sizeof(process_t));
    newProcess->id = id;
    newProcess->arrivalTime = arrivalTime;
    newProcess->burstTime = burstTime;
    newProcess->remainingTime = burstTime;  // Initialize remaining time to burst time
    newProcess->completionTime = 0;
    newProcess->turnAroundTime = 0;
    newProcess->waitingTime = 0;
    newProcess->next = NULL;
    return newProcess;
}

// Function to add a process to the end of the linked list
void addProcess(process_t** head, int id, int arrivalTime, int burstTime) {
    process_t* newProcess = createProcess(id, arrivalTime, burstTime);
    if (*head == NULL) {
        *head = newProcess;
    } else {
        process_t* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProcess;
    }
}

// Function to implement Round Robin Scheduling
void roundRobinScheduling(process_t* head, int timeQuantum) {
    int time = 0;
    process_t* cur = head;
    int completed = 0;
    int numProcesses = 0;

    // Calculate the number of processes
    for (process_t* temp = head; temp != NULL; temp = temp->next) {
        numProcesses++;
    }

    while (completed < numProcesses) {
        if (cur->remainingTime > 0) {
            if (cur->remainingTime > timeQuantum) {
                time += timeQuantum;
                cur->remainingTime -= timeQuantum;
            } else {
                time += cur->remainingTime;
                cur->completionTime = time;
                cur->turnAroundTime = cur->completionTime - cur->arrivalTime;
                cur->waitingTime = cur->turnAroundTime - cur->burstTime;
                cur->remainingTime = 0;
                completed++;
            }
        }
        // Move to the next process
        cur = (cur->next != NULL) ? cur->next : head;
    }
}

// Function to calculate and display average waiting time and turnaround time
void calculateAndDisplayAverages(process_t* head) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int numProcesses = 0;

    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (process_t* temp = head; temp != NULL; temp = temp->next) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", temp->id, temp->arrivalTime, temp->burstTime, temp->completionTime, temp->turnAroundTime, temp->waitingTime);
        totalWaitingTime += temp->waitingTime;
        totalTurnaroundTime += temp->turnAroundTime;
        numProcesses++;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / numProcesses);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / numProcesses);
}

int main() {
    process_t* processList = NULL;

    // Adding processes (id, arrival time, burst time)
    addProcess(&processList, 1, 0, 5);
    addProcess(&processList, 2, 1, 4);
    addProcess(&processList, 3, 2, 2);
    addProcess(&processList, 4, 3, 1);

    int timeQuantum = 2;
    roundRobinScheduling(processList, timeQuantum);
    calculateAndDisplayAverages(processList);

    return 0;
}
