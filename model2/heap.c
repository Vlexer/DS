#include<stdio.h>
#include<stdlib.h>

typedef struct Heap {
    int * array;
    int size;
    int capacity;
} Heap;

Heap * createHeap ( int capacity ) {
    Heap *  temp = ( Heap * )malloc( sizeof(Heap) );
    temp->array = ( int * )malloc ( sizeof(int) * capacity );
    temp->capacity = capacity;
    temp->size = 0;
    return temp;
}
void Swap ( int *x, int *y ) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printHeap ( Heap * heap ) {
    for ( int i = 0; i < heap->size; i++ ) {
        printf("%d ",heap->array[i]);
    }
}
int min ( int x, int y ) {
    return x < y ? x : y;
}
int getParentIndex ( Heap *heap, int i ) {
    if ( i >= heap->size || i < 0 ) return -1;
    return ( i - 1 )/2;
}
int getLeftChildIndex ( Heap * heap, int i ) {
    int rightIndex = ( 2 * i ) + 1;
    if ( rightIndex >= heap->size || i < 0 ) return -1;
    return rightIndex; 
}
int getRightChildIndex ( Heap * heap, int i ) {
    int right = ( 2 * i ) + 2;
    if ( right >= heap->size || i < 0 ) return -1;
    return right;
}
void PercolateUp ( Heap * heap, int nodeIndex ) {
    if ( heap == NULL ) return;
    int i = nodeIndex;
    while ( i > 0 ) {
        int parent = getParentIndex(heap, i);
        if ( heap->array[i] < heap->array[parent] ) {
            Swap(&heap->array[i], &heap->array[parent]);
            i = parent;
        } else break;
    }
}
void PercolateDown ( Heap * heap, int nodeIndex ) {
    if ( heap == NULL ) return;
    int i = nodeIndex;
    while ( i < heap->size ) {
        int left = getLeftChildIndex(heap, i);
        int right = getRightChildIndex(heap, i);
        int smallest = i;
        if ( left != -1 && heap->array[left] < heap->array[smallest] ) smallest = left;
        if ( right != -1 && heap->array[right] < heap->array[smallest] ) smallest = right;
        if ( smallest != i ) {
            Swap(&heap->array[i], &heap->array[smallest]);
            i = smallest;
        } else break;
    }
}
void insertHeap ( Heap * heap, int x ) {
    heap->array[heap->size] = x;
    PercolateUp(heap, heap->size++);
}
int deleteHeap ( Heap * heap ) {
    int del = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    PercolateDown(heap, 0);
    return del;
}
int keyToIndex ( Heap * heap, int key ) {
    for ( int i = 0; i < heap->size; i++ ) {
        if ( heap->array[i] == key ) return i;
    }
    return -1;
}
void decreasekey ( Heap * heap, int key, int del ) {
    int nodeIndex = keyToIndex(heap,key);
    if ( nodeIndex != -1 ) {
        heap->array[nodeIndex] -= del;
        PercolateUp(heap, nodeIndex);
    } else {
        printf("Node doesnt exist\n");
    }
}
void removeHeap ( Heap * heap, int x ) {
    if ( keyToIndex(heap, x) != -1 ) {
        decreasekey(heap, x, 12121212);
        deleteHeap(heap);
    } else {
        printf("Node doesnt exist\n");
    }
}
int getInt ( char * s ) {
    printf("%s ", s);
    int x;
    scanf("%d", &x);
    return x;
}
int main () {
    int ch = getInt("Enter 1 to insert\n2 To Delete\n 3 to Remove\n4 To print\n");
    Heap * heap = createHeap(20);
    while ( 1 ) {
        switch ( ch ) {
            case 1:{
                int x = getInt("Enter the element to insert ");
                insertHeap(heap, x);
                printf("Successfully added\n");
                break;
            }
            case 2:{
                if ( heap->size == 0 ) {
                    printf("Heap is empty\n");
                } else  {
                    printf("min element = %d\n", deleteHeap(heap));
                }
                break;
            }
            case 3:{
                int x = getInt("Enter the element to delete");
                removeHeap(heap,x);
                printf("Element %d is remove\n", x);
                break;
            }
            case 4:{
                printHeap(heap);
                break;
            }
        }
        ch = getInt("Enter 1 to insert\n2 To Delete\n 3 to Remove\n4 To print\n");
    }

}   