#include<stdio.h>
#include<stdlib.h>

typedef struct Heap {
    int * array;
    int size;
    int capacity;
} Heap;

Heap * heapInit ( int cap ) {
    Heap * temp = ( Heap * )malloc( sizeof(Heap) );
    temp->array = ( int * )malloc ( sizeof( int ) * cap );
    temp->capacity = cap;
    temp->size = 0;
    return temp;
}

int getLeftChild ( Heap * heap, int index ) {
    int leftChild = 2 * index + 1;
    if ( leftChild > 0 && leftChild  < heap->size ) return leftChild;
    return -1; 
}

int getRightChild ( Heap * heap, int index ) {
    int rightIndex = 2 * index + 2;
    if ( rightIndex > 0 && rightIndex < heap->size ) return rightIndex;
    return -1;
}
int getParent ( Heap * heap, int index ) {
    if ( index < heap->size && index >= 0 ) {
        return ( index - 1 )/2;
    }
}
void swap ( int * x, int * y ) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void percolateUp ( Heap * heap, int index ) {
    if ( heap == NULL || index > heap->size || index < 0 ) return;
    int i = index;
    while ( i > 0 ) {
        int parent = getParent(heap, i);
        if ( heap->array[i] < heap->array[parent] ) {
            swap(&heap->array[i], &heap->array[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void percolateDown ( Heap * heap, int index ) {
    if ( heap == NULL || index > heap->size || index < 0 ) return;
    int i = index;
    while ( i < heap->size ) {
        int left = getLeftChild(heap, i);
        int right = getRightChild(heap, i);
        int smallest = i;
        if ( left != -1 && heap->array[left] < heap->array[smallest] ) smallest = left;
        if ( right != -1 & heap->array[right] < heap->array[smallest] ) smallest = right;
        if ( i != smallest ) {
            swap(&heap->array[i], &heap->array[smallest]);
            i = smallest;
        } else break;
    }
}

void insert ( Heap * heap, int x ) {
    if ( heap == NULL || heap->size == heap->capacity ) return;
    heap->array[heap->size] = x;
    percolateUp(heap, heap->size++);   
}
int delete( Heap * heap ) {
    if ( heap == NULL || heap->size == 0 ) return -12;
    int del = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    percolateDown(heap,0);
    return del;
}
void Heapify ( Heap * heap ) {
    int i = (heap->size/2 ) - 1;
    while ( i >= 0 ) {
        percolateDown(heap, i);
        i--;
    }
}
void printHeap ( Heap * heap ) {
    for ( int i = 0; i < heap->size; i++ ) {
        printf("%d ", heap->array[i]);
    }
}

int getInt ( char *s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}

int main () {
    Heap * heap = heapInit(10);   
    int ch = getInt("Enter 1 to insert 2 to delete 3  to print");
    while ( 1 ) {
        switch ( ch ) {
            case 1 : {
                int x = getInt("Enter the number to insert");
                insert(heap, x);
                printHeap(heap);
                break;
            } case 2:{
                if ( heap->size == 0 ) {
                    printf("Heap is empty\n");
                    break;
                } 
                int x = delete(heap);
                printf("The deleted node is  %d\n", x);
                printHeap(heap);
                break;
            } case 3:{
                printHeap(heap);
            }
        }
        ch = getInt("Enter 1 to insert 2 to delete 3  to print"); 
    }
    return 0;
}
