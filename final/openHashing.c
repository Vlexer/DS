#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node;

typedef struct OpenHashTable {
    node ** buckets;
    int size;
} OpenHashTable;

node * createNode ( int x ) {
    node * temp = ( node *)malloc( sizeof(node) );
    temp->data= x;
    temp->next = NULL;
    return temp;
}

OpenHashTable * OpenHashTableInit ( int size ) {
    OpenHashTable * temp = ( OpenHashTable * )malloc ( sizeof( OpenHashTable ));
    temp->buckets = ( node ** )malloc ( sizeof(node *) * size );
    temp->size = size;
    for ( int i = 0; i < size; i++ ) {
        temp->buckets[i] = NULL;
    }
    return temp;
}

// void insertAtBeg ( node ** head, int x ) {
//     node * temp = createNode(x);
//     temp->next = *head;
//     *head = temp;
// }
// void deleteElement ( node ** head, int x ) {
//     if ( *head == NULL ) {
//         printf("List is empty\n");
//         return;
//     }
//     node * cur = *head;
//     node * prev = NULL;
//     while ( cur != NULL && cur->data != x ) {
//         prev = cur;
//         cur = cur->next;
//     }
//     if ( cur == NULL ) {
//         printf("node doesnt exist\n");
//         return;
//     }
//     if ( prev == NULL ) {
//         *head = cur->next;
//     } else {
//         prev->next =cur->next;
//     }
//     free(cur);
// }

void insertAtBeg ( node ** head, int x ) {
    node * temp = createNode(x);
    temp->next = *head;
    *head = temp;
}

void deleteElement ( node ** head, int x ) {
    if ( *head == NULL ) return;
    node * cur = *head;
    node * prev = NULL;
    while ( cur && cur->data != x ) {
        prev = cur;
        cur = cur->next;
    }
    if ( cur == NULL ) {
        printf("Node doesnt exist\n");
        return;
    } if ( prev == NULL ) {
        *head = cur->next;
        return;
    } else {
        prev->next = cur->next;
    }
    free(cur);
}

int Hashfunction ( int key, int size )
 {
    return key % size;
 }

void insert(OpenHashTable * table, int x) {
    int index = Hashfunction(x, table->size);
    insertAtBeg(&table->buckets[index], x);
}

void delete ( OpenHashTable * table , int x ) {
    int index = Hashfunction(x, table->size);
    deleteElement(&table->buckets[index], x);
}
void printTable ( OpenHashTable * table ) {
    for ( int i = 0; i < table->size; i++ ) {
        printf("Bucket %d : ", i);
        node * cur = table->buckets[i];
        while ( cur != NULL ) {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
        printf("NULL\n");
    } 
}

void Search ( OpenHashTable * table, int x ) {
    int index = Hashfunction(index, table->size);
    node * cur = table->buckets[index];
    while ( cur != NULL ) {
        if ( cur->data == x ) {
            printf("Element found at index %d", index);
            return;
        } 
        cur = cur->next;
    }
    printf("Element not found\n");
}

int main () {
    OpenHashTable * table = OpenHashTableInit(10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 20);
    delete(table, 10);
    
    Search(table, 10);
    printTable(table);
}

