#include <stdio.h>
#define MAX 100

int isSafe(
    int processes, int resources, int available[],
    int max[][MAX], int allocation[][MAX], int need[][MAX], int safeseq[]) 
{
    int work[MAX], finish[MAX] = {0};
    
    for (int i = 0; i < resources; i++) 
        work[i] = available[i];

    int count = 0;
    while (count < processes) {
        int found = 0;
        for (int p = 0; p < processes; p++) {
            if (!finish[p]) {
                int canExecute = 1;
                for (int r = 0; r < resources; r++) {
                    if (need[p][r] > work[r]) {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute) {
                    safeseq[count++] = p;
                    for (int r = 0; r < resources; r++)
                        work[r] += allocation[p][r];

                    finish[p] = 1;
                    found = 1;
                    break;
                }
            }
        }
        
        if (!found)
            return 0;
    }
    return 1;
}

int main() {
    int processes, resources;
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resource types: ");
    scanf("%d", &resources);

    int allocation[MAX][MAX] = {0}, max[MAX][MAX] = {0}, need[MAX][MAX] = {0};
    int available[MAX] = {0}, safeseq[MAX] = {0};

    printf("\nEnter allocation matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

    printf("\nEnter maximum need matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter available resources:\n");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    printf("\nNeed Matrix (Max - Allocation):\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    if (isSafe(processes, resources, available, max, allocation, need, safeseq)) {
        printf("\nTHE SYSTEM IS IN SAFE STATE\n");
        printf("Safe sequence: ");
        for (int i = 0; i < processes; i++) {
            printf("P%d", safeseq[i]);
            if (i < processes - 1)
                printf(" -> ");
        }
    } else {
        printf("\nTHE SYSTEM IS NOT IN A SAFE STATE\n");
    }

    return 0;
}
