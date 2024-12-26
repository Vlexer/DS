#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct String {
    char * string;
    int size;
} String;

typedef struct Hashtable {
    String ** array;
    int * tombstone;
    int size;
} Hashtable;

String * createString ( char * s ) {
    String * temp = ( String * )malloc( sizeof(String) );
    temp->size = strlen(s);
    temp->string = ( char * )malloc( sizeof(char) * (temp->size + 1) );
    strcpy(temp->string, s);
    return temp;
}

Hashtable * HashtableInit( int size ) {
    Hashtable * temp = ( Hashtable * )malloc( sizeof(Hashtable));
    temp->array = ( String ** )malloc ( sizeof(String *) * size );
    temp->size = size;
    temp->tombstone = ( int *)malloc( sizeof(int) * size );
    for ( int i = 0; i < size; i++ ) {
        temp->tombstone = 0;
        temp->array[i] = NULL;
    }
}

int hash( int key, int size, int col ) {
    return ( key + col ) % size;
}

void insert ( Hashtable * table, int roll , char * name )
{   
    int col = 0;
    int index = hash (roll, table->size, col);
    while ( table->array[index] != NULL && table->tombstone == 0 ) {
        col++;
        index = hash(roll, table->size, col);
    }
    String * temp = createString(name);
    table->array[index] = temp;
    table->tombstone[index] = 0;
}

// void delete ( Hashtable * table, int roll ) {
//     int col = 0;
//     int index = hash(roll, table->size, col);
//     while ( table->array[index] != NULL ) {
//         if ( strcmp(table->array[index]->string, ) )
//     }
// }
