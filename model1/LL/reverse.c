#include<stdio.h>
#include<stdlib.h>

typedef struct node_t
{
    /* data */
    int data;
    struct node_t * next;
} node_t;

void createNodeAtEnd ( node_t ** head, int x ) {
    node_t * temp = ( node_t * ) malloc ( sizeof(node_t) );
    temp->data = x;
    temp->next = NULL;
    node_t * cur;

    if ( *head == NULL ) {
        *head = temp;
        return;
    } 

    for ( cur = *head; cur->next != NULL; cur = cur->next );
    cur->next =temp;

}

void printLL( node_t ** head ) {
    for ( node_t * cur = *head; cur != NULL; cur = cur->next  ) {
        printf("%d ", cur->data);
    }
}

void reverse ( node_t ** head ) {
    if ( *head == NULL ) return ;
    if ( (*head)->next == NULL ) return ;
    node_t * prev = NULL, *cur = *head;
    for ( cur = *head; cur != NULL; ) {
        node_t  * temp = cur->next;
        cur->next = prev;
        prev  = cur;
        cur = temp;
    }
    *head = prev;
   
}


node_t * getKthNode ( node_t * head, int k ) {
    node_t * cur = head;
    while ( cur != NULL && k > 0 ) {
        cur = cur->next;
        k--;
    }
    return cur;
}

void reverseByGroup ( node_t ** head, int k ) {
    node_t * dummy = NULL;
    createNodeAtEnd(&dummy, -1);
    dummy->next = *head;
    node_t * groupPrev = dummy;
    while ( 1 ) {
        node_t * kth = getKthNode(groupPrev, k);
        if ( kth == NULL ) break;
        node_t * groupNext = kth->next;
        node_t * prev = groupNext, *cur = groupPrev->next;
        while ( cur != groupNext ) {
            node_t * temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        node_t *temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }

    *head = dummy->next;
}



void main () {
    printf("Enter the number of elements in the linked list\n");
    int size;
    scanf("%d", &size);
    printf("Enter the elements\n");
    node_t * head = NULL;
    for ( int i = 0 ; i < size; i++ ) {
        int x;
        scanf("%d", &x);
        createNodeAtEnd(&head, x);
    }
    reverseByGroup(&head, 3);
    
    printLL(&head);


}
