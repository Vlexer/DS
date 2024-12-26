#include<stdio.h>
#include<stdlib.h>

typedef struct node_t {
    int data;
    struct node_t * next;
} node_t;

typedef struct Hashtable {
    int size;
    node_t ** Table;
} Hashtable;

Hashtable * createHashTable ( int size ) {
    Hashtable * temp = ( Hashtable * )malloc( sizeof(Hashtable));
    temp->size = size;
    temp->Table = ( node_t ** )malloc( sizeof(node_t *) * size );
    return temp;
}
node_t * createNode ( int x ) {
    node_t * temp = ( node_t *  )malloc ( sizeof(node_t) ) ;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void insertAtBegin ( node_t **head, int x ) {
    node_t * temp = createNode(x);
    node_t * oldHead = *head;
    *head = temp;
    temp->next = oldHead;
}

void deleteLL ( node_t **head, int x ) {
    if ( head == NULL ) return;
    node_t * cur = *head;
    node_t * prev =  NULL;
    while ( cur != NULL && cur->data != x ) {
        prev = cur;
        cur = cur->next;
    }
    if ( cur == NULL ) {
        printf("Node doesnt exist\n");
    }
    else if ( prev == NULL ) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }
}

int hashFunction ( Hashtable * table, int key ) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % 11;
    return x;
}

void insert ( Hashtable * table, int x ) {
    int index = hashFunction(table, x);
    insertAtBegin(&table->Table[index], x);
}

void delete (Hashtable * table , int x) {
    int index = hashFunction(table,x);
    deleteLL(&table->Table[index], x);
}