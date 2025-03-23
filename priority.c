#include<stdio.h>
int n,p[30],bt[30],prio[30],priority_wt=0,priority_tat=0,tot_tat=0,tot_wt=0,tat[30],wt[30];
float avg_tat,avg_wt;
int sort();
int wt_tat(int *a,int *b);
int main(){
    printf("enter the no of processes\n");
    scanf("%d",&n);
    printf("enter the burst time and priority of each processes\n");
    for(int i=0;i<n;i++){
        printf("p[%d] burst time and priority:",i);
        scanf("%d%d",&bt[i],&prio[i]);
        p[i]=i;
    }
    sort();
    printf("\npriority ALGORITHM\n");
    wt_tat(&priority_tat,&priority_wt);
    avg_tat=(float)priority_tat/n;
    avg_wt=(float)priority_wt/n;
    printf("\naverage turn around time:%.2f",avg_tat);
    printf("\ntotal turn around time:%d",priority_tat);
    printf("\naverage waiting time:%.2f",avg_wt);
    printf("\ntotal waiting time:%d",priority_wt);
}
int sort(){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(prio[j]>prio[j+1]){
                temp=prio[j];
                prio[j]=prio[j+1];
                prio[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                
            }
        }
    }
  return 0;
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
    printf("\nPROCESS\t\tBURST TIME\t\tPRIORITY\t\tTURNAROUND TIME\t\tWAITING TIME");
    for(i=0;i<n;i++){
       printf("\np[%d]\t\t%d\t\t%d\t\t\t\t%d\t\t%d",p[i],bt[i],prio[i],tat[i],wt[i]);
       
    }
    return 0;
}


