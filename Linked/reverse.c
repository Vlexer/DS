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

node_t * reverse ( node_t ** head ) {
    
    node_t * prev= NULL, * cur = *head;
    if ( cur->next == NULL ) return cur;
    node_t * afterThat = cur->next;
    while ( cur != NULL ) {
        cur->next = prev;
        prev = cur;
        cur = afterThat;
       if ( afterThat != NULL ) {
        afterThat = afterThat->next;
       }
    }
    return prev;
}

node_t * reverseGroup ( node_t ** head , int k ) {
    node_t * prev = NULL, *cur = *head;
    if ( cur->next == NULL && k > 1 ) return cur;
    int c = 0;
    for( node_t * temp = *head; temp != NULL; temp = temp->next ) c++;
    node_t * afterThat = cur->next;
    node_t * res;
    node_t * (* smaller ) = (node_t *) malloc ( sizeof(node_t *) * (c/k) );
    int a = 0;
    int j = 1, n = 1;
    while ( cur != NULL ) {
        if ( j != k + 1) {
            cur->next = prev;
            prev = cur;
            cur = afterThat;
            if ( afterThat != NULL ) afterThat = afterThat->next;
            j++;
        } else {
            j = 1;
            if ( n++ == 1 ) res = prev;
            node_t * temp;
            for ( temp = prev; temp->next != NULL; temp = temp->next );
            prev = NULL;
            smaller[a++] = temp;
            
        }
    }
    return res;
}



void main () {
    node_t * head = NULL;
    createNode(&head, 1);
    createNode(&head, 2);
    createNode(&head, 3);
    createNode(&head, 4);
    createNode(&head, 5);
    node_t * res = reverseGroup( &head, 3 );
    printLL(res);
}