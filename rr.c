#include<stdio.h>
int tq,n,tat[30],wt[30],tot_tat=0,tot_wt=0,rr_tat=0,rr_wt=0,p[30],bt[30],rem_bt[30],quantum;
float avg_wt,avg_tat;
int wt_tat(int*a,int*b);
int main(){
    printf("\nenter the no of process");
    scanf("%d",&n);
    printf("\nenter the burst time of procesess");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
        p[i]=i;
    }
    printf("\nenter the time slice");
    scanf("%d",&tq);
    printf("\nROUND ROBIN");
    wt_tat(&rr_tat,&rr_wt);
    avg_tat=(float)rr_tat/n;
    avg_wt=(float)rr_wt/n;
    printf("\naverage turn around time:%.2f",avg_tat);
    printf("\ntotal turn around time:%d",rr_tat);
    printf("\naverage waiting time:%.2f",avg_wt);
    printf("\ntotal waiting time:%d",rr_wt);
}
int wt_tat(int *a,int *b){
    int t=0,remaining_pr=n;
    while(remaining_pr>0)
    {
        for(int i=0;i<n;i++)
        {
              if(rem_bt[i]>0)
              {
                if(rem_bt[i]>tq){
                    t+=tq;
                    rem_bt[i]-=tq;
                }
                else{
                    t+=rem_bt[i];
                    tat[i]=t;
                    rem_bt[i]=0;
                    remaining_pr--;
                   }
              }
        }
    }
    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        tot_tat+=tat[i];
        tot_wt+=wt[i];
    }
    *a=tot_tat;
    *b=tot_wt;
    printf("\nPROCESS\tBURST TIME\tTURNAROUND TIME\tWAITING TIME");
    for (int i = 0; i < n; i++) {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], tat[i], wt[i]);
    }

    return 0;
}
