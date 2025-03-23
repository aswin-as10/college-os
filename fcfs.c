#include<stdio.h>
int n,p[30],bt[30],tot_tat=0,wt[30],tot_wt=0,tat[30],fcfs_tat=0,fcfs_wt=0;
float avg_wt=0,avg_tat=0;
int wt_tat(int *a,int *b);
int main(){
    printf("enter the no of processes\n");
    scanf("%d",&n);
    printf("enter the burst time of each processes\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    printf("\nFCFS ALGORITHM\n");
    wt_tat(&fcfs_tat,&fcfs_wt);
    avg_tat=(float)fcfs_tat/n;
    avg_wt=(float)fcfs_wt/n;
    printf("\naverage turn around time:%.2f",avg_tat);
    printf("\ntotal turn around time:%d",fcfs_tat);
    printf("\naverage waiting time:%.2f",avg_wt);
    printf("\ntotal waiting time:%d",fcfs_wt);

}
int wt_tat(int *a,int *b){
     int i;
     for(i=0;i<n;i++){
        if(i==0)
            tat[i]=bt[i]; 
        else
          tat[i]=tat[i-1]+bt[i];
        tot_tat=tot_tat+tat[i];
     }
     *a=tot_tat;
     wt[0]=0;
     for(i=0;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
     }
     *b=tot_wt;
     printf("\nPROCESS\t\tBURST TIME\t\tTURNAROUND TIME\t\tWAITING TIME");
     for(i=0;i<n;i++){
        printf("\np[%d]\t\t%d\t\t\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
        
     }
     return 0;
}
