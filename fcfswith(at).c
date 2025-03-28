#include<stdio.h>
int tat[30],wt[30],i,tot_tat=0,tot_wt=0,n,bt[30],p[30],fcfs_tat=0,fcfs_wt=0,at[30],ct[30];
float avg_wt,avg_tat;
int wt_tat(int *a,int *b);
int sort();
int main(){
    printf("\nenter the no of processes");
    scanf("%d",&n);
    printf("\nenter the at and bt of processes");
    for(i=0;i<n;i++){
        scanf("%d%d",&at[i],&bt[i]);
        p[i]=i;
    }
    sort();
    printf("nFCFS");
    wt_tat(&fcfs_tat,&fcfs_wt);
    avg_tat=(float)fcfs_tat/n;
    avg_wt=(float)fcfs_wt/n;
    printf("\naverage turn around time:%.2f",avg_tat);
    printf("\ntotal turn around time:%d",fcfs_tat);
    printf("\naverage waiting time:%.2f",avg_wt);
    printf("\ntotal waiting time:%d",fcfs_wt);
}
int sort(){
    int temp;
    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
int wt_tat(int *a,int *b){
    int time=0;
    for(i=0;i<n;i++){
        if(time<at[i]){
            time=at[i];
        }
        ct[i]=time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        tot_tat+=tat[i];
        tot_wt+=wt[i];
        time=ct[i];
    }
    *a=tot_tat;
    *b=tot_wt;
     printf("\nPROCESS\t\tARRIVAL TIME\t\tBURST TIME\t\tTURNAROUND TIME\t\tWAITING TIME");
     for(i=0;i<n;i++){
        printf("\np[%d]\t\t%d\t\t%d\t\t\t\t%d\t\t%d",p[i],at[i],bt[i],tat[i],wt[i]);
        
     }
     return 0;


    
}
