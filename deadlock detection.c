#include<stdio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main() {
    printf("********** Deadlock Detection Algo ************\n");
    input();
    show();
    cal();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);
    
    printf("Enter the Max Matrix\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Available Resources\n");
    for(j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("\nProcess\t Allocation\t Max\t Available\n");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t ", i+1);
        for(j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for(j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if(i == 0) {
            for(j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
    }
}

void cal() {
    int finish[100] = {0};
    int flag = 1, c1 = 0;
    int dead[100];
    int i, j, k;

    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    while(flag) {
        flag = 0;
        for(i = 0; i < n; i++) {
            int c = 0;
            for(j = 0; j < r; j++) {
                if(finish[i] == 0 && need[i][j] <= avail[j]) {
                    c++;
                }
            }
            if(c == r) {
                for(k = 0; k < r; k++) {
                    avail[k] += alloc[i][k];
                }
                finish[i] = 1;
                printf("P%d->", i+1);
                flag = 1;
            }
        }
    }

    int deadlock_detected = 0;
    int j = 0;
    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock_detected = 1;
            dead[j] = i;
            j++;
        }
    }

    if(deadlock_detected) {
        printf("\n\nSystem is in Deadlock and the Deadlock process are:\n");
        for(i = 0; i < j; i++) {
            printf("P%d\t", dead[i] + 1);
        }
    } else {
        printf("\nNo Deadlock Occurred\n");
    }
}
