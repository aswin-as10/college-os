#include<stdio.h>
int alloc[30][30],max[30][30],need[30][30],avail[30],r,n;
void input();
void show();
void cal();
void input(){
    int i,j;
    printf("\nenter the no of processes");
    scanf("%d",&n);
    printf("\nenter the no of resources");
    scanf("%d",&r);
    printf("\nenter the allocation matrix");
    for(i=0;i<n;i++)
      for(j=0;j<r;j++)
         scanf("%d",&alloc[i][j]);
    printf("\nenter the max matrix");
    for(i=0;i<n;i++)
       for(j=0;j<r;j++)
        scanf("%d",&max[i][j]);
    printf("\nenter the available matrix");
    for(j=0;j<r;j++)
      scanf("%d",&avail[j]);

}
void show(){
    int i,j;
    printf("\nPROCESS\tALLOCATION\tMAX\tAVAILABLE");
    for(i=0;i<n;i++)
        printf("p%d",i);
        for(j=0;j<r;j++)
            printf("%d",alloc[i][j]);
        
        printf("\n");
        for(i=0;i<n;i++)
           for(j=0;j<r;j++)
             printf("%d",max[i][j]);
        
       printf("\n");
        if(i==0)
            for(j=0;j<r;j++)
                printf("%d",avail[j]);
      
       
    
}
void cal() {
    int finish[100] = {0}, safeSeq[100], index = 0;
    int i, j, flag = 1, processExecuted;

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nSafe Sequence: ");
    
    while (flag) {
        flag = 0;
        processExecuted = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {  // Process is not yet completed
                int canAllocate = 1;

                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canAllocate = 0;  // Cannot allocate resources
                        break;
                    }
                }

                if (canAllocate) {
                    for (j = 0; j < r; j++)
                        avail[j] += alloc[i][j];  // Release resources
                    
                    finish[i] = 1;
                    safeSeq[index++] = i;  // Store in safe sequence
                    processExecuted = 1;
                    flag = 1;
                }
            }
        }

        if (processExecuted == 0) break; // Prevents infinite loop if system is unsafe
    }

    // Check if all processes were executed
    if (index == n) {
        printf("\nThe system is in a SAFE state.\nSafe Sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("\nThe system is NOT in a safe state.\n");
    }
}


