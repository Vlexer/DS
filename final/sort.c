#include<stdio.h>
#include<stdlib.h>
int swaps = 0;
void Shellsort ( int * a, int l ) {
    for ( int interval = l/2; interval > 0 ; interval /= 2 ) {
        for ( int i = interval; i < l; i++ ) {
            int j; int temp = a[i];
            for ( j = i; j - interval >= 0 && a[j - interval] >= temp; j-=interval ) {
                a[j] = a[j-interval];
            }
            a[j] = temp;
        }
    }
}

void insertionSort ( int *a, int l ) {
    for ( int i = 1; i < l; i++ ) {
        int j = i - 1;
        int temp = a[i];
        while ( j >= 0 ) {
            if ( a[j] > temp ) {
                a[j+1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }
}
void printArray(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge ( int *a, int l, int mid, int r ) {
    int l1 = mid - l + 1;
    int l2 = r - mid;

    int * L = ( int * )malloc ( sizeof(int) * l1 );
    int * R = ( int * )malloc ( sizeof(int) * l2 );

    for ( int i = 0 ; i < l1; i++ ) {
        L[i] = a[l + i];
    }
    for ( int i = 0 ; i < l2; i++ ) {
        R[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while ( i < l1 && j < l2 ) {
        if ( L[i] <= R[j] ) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while ( i < l1 ) a[k++] = L[i++];
    while ( j < l2 ) a[k++] = R[j++];
    printf("Left subarray : ");
    for ( int i = 0; i < l1; i++ ) printf("%d ", L[i]);
    printf("Right SubArray : ");
    for ( int i = 0; i < l2; i++ ) printf("%d ", R[i]);
    printf("Sorted Sub array : \n");
    for ( int i = l; i <= r; i++) printf("%d ", a[i]);
    printf("\n");
    free(L);
    free(R); 
}

void mergeSort ( int *a, int l, int r ) {
    if ( l < r ) {
        int mid = ( l + r )/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l,mid,r);
    }
}

int main () {
    int a[] = { 9,8,7,6,5,4 };
    mergeSort(a, 0, 5);
    printArray(a, 6);
    printf("NUmber of swaps = %d\n", swaps);
    return 0;
}