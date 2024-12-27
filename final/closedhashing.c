#include<stdio.h>
#include<stdlib.h>

typedef struct HashTable {
    int * array;
    int size;
    int * tombstone;
} HashTable;

HashTable * HashTableInit ( int size ) {
    HashTable * temp = ( HashTable * )malloc ( sizeof(HashTable) );
    temp->array = ( int * )malloc ( sizeof(int) * size );
    temp->size = size;
    temp->tombstone =  ( int * )malloc ( sizeof(int) * size );
    for ( int i = 0; i < size; i++ ) {
        temp->array[i] = -1;
        temp->tombstone = 0;
    }
    return temp;
}
int hashfunction ( int key, int size, int collision ) {
    return  ( key + collision ) % size;
}

void insert ( HashTable *table, int x ) {
    int col = 0;
    int index = hashfunction(x, table->size, col);
    while ( table->array[index] != -1 && table->tombstone[index] == 0 ) {
        col++;
        index = hashfunction(x, table->size, col);
        printf("Probed at index %d\n", index);
    }
    table->array[index] = x;
    table->tombstone[index] = 0;
    printf("Inserted at index %d \n", index);
}
void delete ( HashTable * table, int x ) {
    int col = 0;
    int index = hashfunction(x, table->size, col);
    while ( table->array[index] != -1 ) {
        if ( table->array[index] == x && table->tombstone[index] == 0) {
            table->tombstone[index] = 1;
            printf("deleted %d at index %d\n", x, index);
            return;
        }
        col ++;
        index = hashfunction(x, table->size, col);
    }
    printf("element not found\n");
} 