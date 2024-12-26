#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
typedef struct process {
    int pid;
    int priority;
    int bt;
    int wt;
    int tat;
} process;


void main() {
    int n,i,time = 0;
    float wtavg = 0, tatavg = 0;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    process p[n];
    for ( i = 0; i < n; i++ ) {
        printf("Enter the process Id , burst time and Priority (Lower the number higher the priority ) \n");
        scanf("%d %d %d",&p[i].pid,&p[i].bt,&p[i].priority);
        p[i].wt = 0;
        p[i].tat = 0;
    }
    printf("Enter 1 for FCFS 2 for SJF 3 for Round Robing 4 for Priority\n");
    int ch;
    scanf("%d",&ch);
    while ( ch != 5 ) {
        switch ( ch ) {
            case 2: {
                for ( int i = 0; i < n - 1; i++ ) {
                    for ( int j = 0; j < n- i -1; j++) {
                        if ( p[j].priority > p[j + 1].priority ) {
                             process temp = p[j];
                            p[j] = p[j + 1];
                            p[j + 1] = temp;
                        }
                }
   
            }
             p[0].wt = 0;
            for( i = 1; i < n; i++ ) {
                p[i].wt = p[i - 1].wt + p[ i -1 ].bt;
            }
            for (int i = 0 ; i < n; i++ ) {
                 p[i].tat = p[i].wt + p[i].bt;
            }


            for ( int i = 0; i < n; i++ ) {
                    printf("For Process %d\n",i+1);
                    printf("Wait time : %d\n",p[i].wt);
                    printf("Turn Around Time : %d\n\n", p[i].tat);
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
    break;
            }
            case 4: {
                for ( int i = 0; i < n - 1; i++ ) {
        for ( int j = 0; j < n- i -1; j++) {
                if ( p[j].priority > p[j + 1].priority ) {
                        process temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
       }
   }
   
    }
    p[0].wt = 0;
    for( i = 1; i < n; i++ ) {
        p[i].wt = p[i - 1].wt + p[ i -1 ].bt;
    }
    for (int i = 0 ; i < n; i++ ) {
        p[i].tat = p[i].wt + p[i].bt;
    }


    for ( int i = 0; i < n; i++ ) {
        printf("For Process %d\n",i+1);
        printf("Wait time : %d\n",p[i].wt);
        printf("Turn Around Time : %d\n\n", p[i].tat);
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
                break;
            }
            case 3: {
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
    break;
            }
            case 1: {
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
break;
            }
            
        }
        printf("\n\nEnter 1 for FCFS 2 for SJF 3 for Round Robing 4 for Priority\n");
        scanf("%d",&ch);
    }
    


}