#include<stdio.h>
#include<stdlib.h>

void wait ( int * x ) {
    *x = *x - 1;
}

void signal ( int * x ) {
    *x = *x + 1;
}

typedef struct node_t {
    int data;
    struct node_t * next;
} node_t;

void createNode ( node_t ** head, int x ) {
    node_t * temp;
    temp = *head;
    node_t * newNode = ( node_t * ) malloc( sizeof(node_t) );
    newNode->data = x;
    newNode->next = NULL;
    if ( *head == NULL ) {
        *head = newNode;
    } else {
        node_t * cur;
        for ( cur = *head; cur->next != NULL ; cur = cur->next );
        cur->next = newNode;
    }
}

node_t * deleteNodeAtBeg( node_t ** head ) {
    if ( *head == NULL ) {
        return NULL;
    } 
    node_t * temp = *head;
    if ( temp->next == NULL ) {
        *head = NULL;
        return temp;
    } 
    *head = temp->next;
    return temp;
}
int findTheSizeOftheQueue ( node_t ** head ) {
    if ( *head == NULL ) {
        return 0;
    }
    node_t * temp = *head;
    if ( temp->next == NULL ) {
        return 1;
    }
    node_t * cur;
    int l = 0;
    for ( cur = *head; cur != NULL ; cur = cur->next) {
        l++;
    }
    return l;

}

void printLL( node_t * head ) {
    node_t * cur;
    for ( cur = head; cur != NULL; cur = cur->next ) {
        printf("%d ",cur->data);
    }
}

void main () {
    printf("Enter the size of the buffer\n");
    int sizeOfBuffer;
    scanf("%d",&sizeOfBuffer);
    printf("Enter 1 to Produce\n 2 to consume\n 3 to print the contents of buffer\n 4 to exit\n");
    int ch;
    scanf("%d",&ch);
    node_t * head = NULL;
    node_t * front = NULL;
    node_t * rear = NULL;
    int MUTEX = 1;
    int FULL = 0;
    int EMPTY = sizeOfBuffer;
    while ( ch != 4 ) {
        switch (ch)
        {
        case 1:
            {
                /* code */
                printf("enter the data\n");
                int data;
                scanf("%d",&data);
                wait(&EMPTY);
                wait(&MUTEX);
                if ( findTheSizeOftheQueue(&head) < sizeOfBuffer ) {
                    createNode(&head, data);
                    printf("The Produced Element is %d\n",data);
                } else {
                    printf("The Buffer is FUll\n");
                }
                signal(&MUTEX);
                signal(&FULL);
                break;
            }
        case 2: {
            wait(&FULL);
            wait(&MUTEX);
            if ( findTheSizeOftheQueue(&head) == 0 ) {
                printf("the Buffer is empty\n");
            } else {
                int x = deleteNodeAtBeg(&head)->data;
                printf("The consumed Element is %d\n",x);
            }
            signal(&EMPTY);
            signal(&MUTEX);
            break;
        }
        case 3: {
            printf("The Buffer elements are\n");
            printLL(head);
            break;
        }
        }
        printf("\nEnter your choice again\n");
        scanf("%d",&ch);
    }

}