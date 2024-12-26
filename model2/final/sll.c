#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    int data;
    struct node_t * next;
} node_t;

node_t * createNode ( int data ) {
    node_t * temp = ( node_t * )malloc ( sizeof(node_t) );
    temp->data = data;
    temp->next = NULL;
    return temp;
} 

int findPosition ( node_t * head, int x ) {
    if ( head == NULL ) return 0;
    node_t * cur = head;
    int pos = 0;
    while ( cur && cur->data < x ) {
        pos++;
        cur = cur->next;
    }
    return pos;
}

void insertAtPos ( node_t ** head, int x, int pos ) {
    node_t * temp = createNode(x);
    if ( *head == NULL || pos == 0 ) {
        temp->next = *head;
        *head = temp;
        return;
    }
    int jumps = pos - 1;
    int i = 0;
    node_t * cur = *head;
    while ( cur && i < jumps ) {
      cur = cur->next;
      i++;  
    } 
    if ( cur != NULL ) {
        temp->next = cur->next;
        cur->next = temp;
    } else {
        printf("invalid\n");
    }
}

void ascendingInsert ( node_t ** head, int x ) {
    int pos = findPosition(*head, x);
    insertAtPos(head, x, pos);
}

void printLL( node_t * head ) {
    node_t * cur = head;
    while ( cur != NULL ) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

}

int main () {
    node_t * head = NULL;
    ascendingInsert(&head, 1);
    ascendingInsert(&head, 2);
    ascendingInsert(&head, 4);
    ascendingInsert(&head, 3);
    ascendingInsert(&head, -1);
    printLL(head);
    return 0;
}