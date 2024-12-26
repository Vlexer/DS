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
	int n,i,time = 0;
	float wtavg = 0, tatavg = 0;
	printf("Enter the number of process\\n");
	scanf("%d",&n);
	process p[n];
	for ( i = 0; i < n; i++ ) {
		printf("Enter the process Id and burst time\n");
		scanf("%d %d",&p[i].pid,&p[i].bt);
		p[i].wt = 0;
		p[i].tat = 0;
	}
	int OGtimeQuantum, timeQuantum;
	printf("Enter the time quantum \n");
	scanf("%d",&OGtimeQuantum);
	int y = n;
	for (int i = 0; y != 0; i = (i + 1) % n, time+=timeQuantum) {
	    timeQuantum = OGtimeQuantum;
		if ( p[i].bt > 0 ) {
			if ( p[i].bt > timeQuantum ) p[i].bt -= timeQuantum;
			else {
				timeQuantum = p[i].bt;
				p[i].tat = time + p[i].bt;
				p[i].bt = 0;
				y--;
				
			}
		}
		for ( int j = 0 ; j < n ; j++ ) {
			if( j != i && p[j].bt != 0 ) p[j].wt += timeQuantum;
		}
	}

	for ( int i = 0; i < n; i++ ) {
	    printf("For Process %d\n",i+1);
	    printf("Wait time : %d\n",p[i].wt);
	    printf("Turn Around Time : %d\n\n", p[i].tat);
		wtavg += p[i].wt;
		tatavg += p[i].tat;
	}
	
	
	printf("\n\n Average Wait time = %f",wtavg/n);
	printf("\n\n Average Turn Around Time is %f", tatavg/n);


}