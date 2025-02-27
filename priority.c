#include <stdio.h>

int p[30], bt[30], priority[30], tot_tat = 0, wt[30], n, tot_wt = 0, tat[30], priority_wt = 0, priority_tat = 0;
float avg_wt, avg_g_tat;

int sort();
int swap(int* a, int* b);
int WT_TAT(int* a, int* b);

void main() {
    int i;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter the burst time and  priority for each process\n");
    for(i = 0; i < n; i++) {
        printf("Process[%d] - Burst time: ", i+1);
        scanf("%d", &bt[i]);
        printf("Process[%d] - Priority: ", i+1);
        scanf("%d", &priority[i]);
        p[i] = i;
    }

    sort();
    WT_TAT(&priority_tat, &priority_wt);
    avg_wt = (float)priority_wt / n;
    avg_g_tat = (float)priority_tat / n;

    printf("\nTotal turnaround time is: %d", priority_tat);
    printf("\nAverage turnaround time: %.2f", avg_g_tat);
    printf("\nTotal waiting time: %d", priority_wt);
    printf("\nAverage waiting time: %.2f", avg_wt);
}

int sort() {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(priority[i] > priority[j]) {
                swap(&priority[j], &priority[i]);
                swap(&bt[j], &bt[i]);
                swap(&p[j], &p[i]);
            }
        }
    }
    return 0;
}

int swap(int* a, int* b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return 0;
}

int WT_TAT(int* a, int* b) {
    int i;

    for(i = 0; i < n; i++) {
        if(i == 0)
            tat[i] = bt[i];
        else
            tat[i] = tat[i-1] + bt[i];

        tot_tat = tot_tat + tat[i];
    }
    *a = tot_tat;

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tot_wt = tot_wt + wt[i];
    }
    *b = tot_wt;

    printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tTURN AROUND TIME\tWAITING TIME");
    for(i = 0; i < n; i++)
        printf("\nProcess[%d]\t%d\t\t%d\t\t%d\t\t\t%d", p[i] + 1, bt[i], priority[i], tat[i], wt[i]);

    return 0;
}


