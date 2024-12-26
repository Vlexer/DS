#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    int data;
    struct node_t * next;
} node_t;

void printLL ( node_t * head ) {
    node_t *cur;
    for ( cur = head; cur != NULL ; cur = cur->next ){
        printf("%d ",cur->data);
    }

}
node_t *  createNode ( node_t ** head, int x ) {
    node_t * temp = ( node_t * ) malloc ( sizeof(node_t) );
    temp->data = x;
    temp->next = NULL;
    if ( *head == NULL ) {
        *head = temp;
        
    } else {
        node_t * cur;
        for( cur = *head; cur->next != NULL; cur = cur->next );
        cur->next = temp;
        
    }
    return temp;
}

node_t * deleteNodeAtBeg( node_t ** head ) {
    node_t * cur = *head;
    if ( *head == NULL) {
        return NULL;
    }   if ( cur->next == NULL ) {
        *head = NULL;
        return cur;
    }  
    
    else {
        node_t * temp = *head;
        node_t * duplic = temp;
        *head = temp->next;
        return duplic;
    }
}

// typedef struct Queue{
//     node_t * front;
//     node_t  *rear;
// } Queue;

// void createQueue ( Queue * s ) {
//     s->front = NULL;
//     s->rear = NULL;
// }

void main () {
    node_t * head = NULL;
    printf("Enter 1 to Enqueue 2 to Dequeue 3 to peek\n");
    int ch;
    scanf("%d",&ch);
    while ( ch != 4 ) {
        switch ( ch ) {
            case 1: {
                printf("Enter the element\n");
                int x; 
                scanf("%d",&x);
                createNode(&head, x);
                printLL(head);
                break;
            }
            case 2: {
                node_t *temp = deleteNodeAtBeg(&head);
                if ( temp != NULL ) printf("dequeued %d\n",temp->data);
                else printf("Queue is Empty\n");
                printLL(head);
                break;
            }
            case 3: {
                if ( head != NULL)
                    printf("front element is %d\n",head->data);
                else {
                    printf("Queue is Empty!!\n");
                }
                break;
            }
        }
        printf("Enter 1 to Enqueue 2 to Dequeue 3 to peek\n");

        scanf("%d",&ch);
    }

}