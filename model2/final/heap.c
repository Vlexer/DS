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
int getParent ( Heap * heap, int index ) {
    if ( index >= heap->size || index < 0 ) return -1;
    return ( index - 1 )/2;
}
int getLeftChild ( Heap * heap, int index ) {
    int leftindex = 2 * index + 1;
    if ( leftindex < 0 || leftindex >= heap->size ) return -1;
    return leftindex;
}
int getRightChild ( Heap * heap, int index ) {
    int leftindex = 2 * index + 2;
    if ( leftindex < 0 || leftindex >= heap->size ) return -1;
    return leftindex;
}
void percolateUp ( Heap * heap, int index ) {
    int i = index;
    while ( i > 0 ) {
        int parent = getParent(heap, i);
        if ( heap->array[parent] < heap->array[index] ) {
            Swap(&heap->array[parent], &heap->array[index]);
            parent = i;
        } else break;
    }
}
void percolateDown ( Heap * heap, int index ) {
    int i = index;
    while ( i < heap->size ) {
        int left = getLeftChild(heap, i);
        int right = getRightChild(heap, i);
        int smallest = i;
        if ( left != -1 && heap->array[left] > heap->array[smallest] ) smallest = left;
        if ( right != -1 && heap->array[right] > heap->array[smallest] ) smallest = right;
        if ( smallest != i ) {
            Swap( &heap->array[i], &heap->array[smallest]);
            i = smallest;
        } else break;
    }
}
void insert ( Heap *heap, int x ) {
    if ( heap->size == heap->capacity ) return;
    heap->array[heap->size] = x;
    percolateUp(heap, heap->size++);
}
int delete ( Heap * heap ) {
    if ( heap->size == 0 ) return -1;
    int del = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    percolateDown(heap, 0);
    return del;
} 
void sort(Heap *heap) {
    int originalSize = heap->size;
    for (int i = originalSize - 1; i >= 0; i--) {
        heap->array[i] = delete(heap);
    }
    heap->size = originalSize; // Restore heap size
}
void findKthLargest ( Heap *heap, int k ) {
    if ( k >= heap->size ) {
        printf("Invalid k value \n");
        return;
    }
    for ( int i = 0; i < k - 1; i++ ) {
        delete(heap);
    }
    printf("Kth largest is %d \n", delete(heap));
}
void increaseKey ( Heap * heap, int index, int del ) {
    heap->array[index] += del;
    percolateUp(heap, index);
}
int main () {
    Heap * heap = createHeap(10);
    insert(heap, 20);
    insert(heap, 10);
    insert(heap, 34);
    insert(heap, 8);
    increaseKey(heap, 3, 10);
    printHeap(heap);
    return 0;
}
