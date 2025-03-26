#include<stdio.h>

int max[100][100], alloc[100][100], need[100][100], avail[100], n, r;

void input();
void show();
void cal();

int main() {
    printf("BANKER'S ALGORITHM\n");
    input();
    show();
    cal();
    return 0;
}


void input() {
    int i, j;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    // Input allocation matrix
    printf("\nEnter the allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    // Input max matrix
    printf("\nEnter the max matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    // Input available resources
    printf("\nEnter the available matrix:\n");
    for(j = 0; j < r; j++)
        scanf("%d", &avail[j]);
}

// Function to display the matrices
void show() {
    int i, j;
    printf("\nPROCESS\tALLOCATION\t\tMAX\t\t\tAVAILABLE\n");
    for(i = 0; i < n; i++) {
        printf("p[%d]\t", i);
        for(j = 0; j < r; j++)
            printf("\t%d", alloc[i][j]);
        printf("\t");
        for(j = 0; j < r; j++)
            printf("\t%d", max[i][j]);
        printf("\t");
        if(i == 0) { 
            for(j = 0; j < r; j++)
                printf("\t%d", avail[j]);
        }
        printf("\n");
    }
}


void cal() {
    int finish[100] = {0}, c1 = 0, flag = 1, i, j, k;

    for(i = 0; i < n; i++)
        for(j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while(flag == 1) {
        flag = 0;  
        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int c = 0;
                for(j = 0; j < r; j++) {
                    if(need[i][j] <= avail[j]) {
                        c++; 
                    }
                }
                if(c == r) {  
                    for(k = 0; k < r; k++)
                        avail[k] = avail[k] + alloc[i][k];

                    finish[i] = 1; 
                    printf("P%d->", i);
                    flag = 1; 
                }
            }
        }
    }


    for(i = 0; i < n; i++) {
        if(finish[i] == 1) {
            c1++;
        }
    }

    if(c1 == n) {
        printf("\nThe system is in a safe state\n");
    } else {
        printf("\nThe system is not in a safe state\n");
    }
}

    

