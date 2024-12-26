#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
typedef struct process {
    int pid;
    int bt;
    int wt;
    int tat;
} process;

void main() {
int n,i;
printf("Enter the number of process\\n");
scanf("%d",&n);
process p[n];
for ( i = 0; i < n; i++ ) {
   printf("Enter the process Id and burst time\n");
   scanf("%d %d",&p[i].pid,&p[i].bt);
}

    p[0].wt = 0;
    for( i = 1; i < n; i++ ) {
        p[i].wt = p[i - 1].wt + p[ i -1 ].bt;
    }
    for(int i = 0 ; i < n; i++) {
         p[i].tat = p[i].bt + p[i].wt;
    }

    float wtavg = 0, tatavg = 0;
    for ( int i = 0; i < n; i++ ) {
        wtavg += p[i].wt;
        tatavg += p[i].tat;
    }
    for ( i = 0; i < n; i++ ) {
        printf("  P%d\t|",p[i].pid);
    }
printf("\n0");
for ( i =0 ; i < n; i++ ) {
printf("\t%d", p[i].wt + p[i].bt);
}
printf("\n\n Average Wait time = %f",wtavg/n);
printf("\n\n Average Turn Around Time is %f", tatavg/n);
}