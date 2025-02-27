#include <stdio.h>

int main() {
    int n, i, tq, time = 0, done;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n], remaining_bt[n], original_bt[n];
    
    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i];  
        original_bt[i] = bt[i];   
        wt[i] = 0;  
        tat[i] = 0;  
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0;
                if (remaining_bt[i] > tq) {
                    time += tq;
                    remaining_bt[i] -= tq;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - original_bt[i]; 
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done) break; 
    }

    for (i = 0; i < n; i++) {
        tat[i] = original_bt[i] + wt[i]; 
    }

    float total_wt = 0, total_tat = 0;
    
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, original_bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
