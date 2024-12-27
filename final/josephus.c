#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node;

node * createNode ( int x ) {
    node * temp = ( node * )malloc( sizeof(node) );
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void Josephus ( node * head, int step ) {

    if ( step == 0 ) {
        printf("not a valid step\n");
        return;
    }
    if ( step == 1 ) {
        node * cur = head;
    
        while ( cur->next != head ) {
            printf("Eliminated node %d\n", cur->data);
            cur = cur->next;
        }
        printf("Eliminated node %d\n", cur->data);
    }

    node * cur = head; 
    node * prev = head;

    while ( cur->next != cur ) {
        for ( int i = 1; i < step; i++ ) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        node * temp = cur;
        cur = cur->next;
        printf("Eliminated node %d\n", temp->data);
        free(temp);
    } 
    printf("WINNING NODE = %d\n", cur->data);
}

void insertAtEnd ( node ** head, int x ) {
    if ( *head == NULL ) {
        node * temp = ( node * )malloc ( sizeof(node) );
        temp->data = x;
        temp->next = temp;
        *head = temp;
        return;
    }
    node * cur = *head;
    while ( cur->next != *head ) {
        cur = cur->next;
    }
    node * temp = createNode(x);
    temp->next = *head;
    cur->next = temp;
}

node * createChain ( int n ) {
    node *head = NULL;
    for ( int i = 0; i < n ; i++ ) {
        insertAtEnd(&head, i+1);
    }
    return head;
}

int main () {
    node * head = createChain(10);
    Josephus(head, 3);
    return 0;
}