#include<stdio.h>
#include<stdlib.h>
int main () {
    FILE *fp = fopen("data.txt", "w");
    int n = 100;
    int i = 0;
    while ( i < n ) {
        fprintf(fp,"%d ", rand());
        i++;
    }
    fclose(fp);
    
}