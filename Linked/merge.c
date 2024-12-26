#include<stdio.h>
#include<stdlib.h> 

typedef struct node_t {
    int data;
    struct node_t * next;

} node_t;

void createNode ( node_t ** head, int data) {
    node_t * temp = ( node_t * )malloc(sizeof(node_t));
    temp->data  = data;
    temp->next = NULL;
    node_t * cur;
    for ( cur = *head; cur != NULL && cur->next != NULL; cur = cur->next );
    if ( cur == NULL ) *head = temp;
    else cur->next = temp;
}

void printLL ( node_t * head ) {
    node_t * cur;
    for ( cur = head; cur != NULL; cur = cur->next ) {
        printf ("%d ",cur->data);

    }
}

node_t * merge ( node_t ** head1, node_t ** head2 ) {
    node_t * res = NULL;
    node_t * cur1 = *head1, * cur2 = *head2;
    
    while ( cur1 != NULL && cur2 != NULL ) {
            if ( cur1->data < cur2->data ) {
                createNode(&res, cur1->data);
                cur1 = cur1->next;
            } else {
                createNode( &res, cur2->data );
                cur2 = cur2->next;
            }
        
    }
    if ( cur1 != NULL ) {
        while ( cur1 != NULL ) {
            createNode(&res, cur1->data);
            cur1 = cur1->next;
        }
    } 
    if ( cur2 != NULL ) {
        while ( cur2 != NULL ) {
            createNode(&res, cur2->data);
            cur2 = cur2->next;
        }
    }
    return res;
}


void main () {
    node_t * head1 = NULL;
    node_t * head2 = NULL;
    createNode(&head1, -2);
    createNode(&head1, 4);
    createNode(&head1, 6);
    createNode(&head1, 80);
    createNode(&head1, 80);

    createNode(&head1, 80);
    createNode(&head2, 1);
    createNode(&head2, 3);
    createNode(&head2, 5);
    node_t * res = merge ( &head1, &head2 );
    printLL(res);
}