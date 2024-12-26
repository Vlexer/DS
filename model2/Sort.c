#include<stdio.h>
#include<stdlib.h>

void shellSort ( int *a, int l ) {
    for ( int interval = l/2; interval > 0; interval/=2 ) {
        for ( int i = interval; i < l; i++ ) {
            int j;
            int temp = a[i];
            for ( j = i; ( j - interval ) >= 0 && a[j-interval] > temp; j-=interval ) {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }  
} 
void insertion (  int *a, int l) {
    for ( int i = 1; i < l; i++ ) {
        int j;int temp = a[i];
        for ( j = i; ( j -1 )>= 0 && a[j-1] > temp; j-=1 ) {
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}
void merge ( int * arr, int l, int m, int r ) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L1[n1], R1[n2];
    for ( int i = 0; i < n1; i++ ) L1[i] = arr[l + i];
    for ( int j = 0; j < n2; j++ ) R1[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while ( i < n1 && j < n2 ) {
        if ( L1[i] <= R1[j] ) arr[k++] = L1[i++];
        else arr[k++] = R1[j++];
    }
    while ( i < n1 ) arr[k++] = L1[i++];
    while ( j < n2 ) arr[k++] = R1[j++];
}

void MergeSort ( int * arr, int l, int r ) {
    if ( l < r ) {
        int m = (l+r)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1, r);
        merge(arr, l,m,r);
    }
}