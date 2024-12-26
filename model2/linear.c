#include<stdio.h>
#include<stdlib.h>

typedef struct Hashtable {
    int * array;
    int * tombstone;
    int nElements;
    int size;
} Hashtable;

Hashtable * createHashtable ( int size ) {
    Hashtable * temp = ( Hashtable * )malloc( sizeof(Hashtable) );
    temp->array = ( int * )malloc( sizeof(int) * size );
    temp->tombstone = ( int * )malloc( sizeof(int) * size );
    temp->size = size;
    temp->nElements = 0;
    for ( int i = 0; i < size; i++ ) {
        temp->array[i] = -1;
        temp->tombstone[i] = 0;
    }
    return temp;
}

int hashfunction ( Hashtable * table, int key, int col ) {
    int x = ( key + 7 ) * ( key + 7 );
    x = x/16;
    x = x + key;
    x = ( x + col ) % table->size;
    return x;
}

void insert ( Hashtable * table, int key ) {
    int col =  0;
    int index = hashfunction(table, key, col);
    while ( table->array[index]  != -1 && table->tombstone[index] == 0 ) {
        col++;
        printf("Probed at index %d unscu\n", index);
        index = hashfunction(table, key, col);
    }
    table->nElements += 1;
    table->array[index] = key;
    table->tombstone[index] = 0;
}

void delete ( Hashtable * table, int key ) {
    int col = 0;
    int index =  hashfunction(table, key, col);
    while ( table->array[index] != -1 ) {
        if ( table->array[index] == key && table->tombstone[index] != 1 ) {
            printf("Element deleted at index %d\n", index);
            table->tombstone[index] = 1;
            table->nElements -= 1;
            return;
        }
        printf("Probed at index %d unsuc\n", index);
        col++;
        index = hashfunction(table, key, col);
    }
    printf("Element not found\n");
}

void printHashtable ( Hashtable * table ) {
    for ( int i =0 ; i < table->size; i++ ) {
        printf("%d " , table->array[i]);
    }
    printf("\n");
} 

