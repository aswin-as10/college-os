#include<stdio.h>
int n,sjf_wt=0,sjf_tat=0,wt[30],tat[30],bt[30],p[30],tot_tat=0,tot_wt=0;
float avg_wt=0,avg_tat;
int wt_tat(int *a,int *b);
int sort();
int main(){
    printf("enter the no of processes\n");
    scanf("%d",&n);
    printf("enter the burst time of each processes\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    sort();
    printf("\nSJF ALGORITHM\n");
    wt_tat(&sjf_tat,&sjf_wt);
    avg_tat=(float)sjf_tat/n;
    avg_wt=(float)sjf_wt/n;
    printf("\naverage turn around time:%.2f",avg_tat);
    printf("\ntotal turn around time:%d",sjf_tat);
    printf("\naverage waiting time:%.2f",avg_wt);
    printf("\ntotal waiting time:%d",sjf_wt);
}
int sort(){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
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
        printf("\nPROCESS\t\tBURST TIME\t\tTURNAROUND TIME\t\tWAITING TIME");
        for(i=0;i<n;i++){
           printf("\np[%d]\t\t%d\t\t\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
           
        }
        return 0;
}
