#include<stdio.h>
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0;
float awt,avg_tat,avg_wt;
int WT_TAT(int*a,int*b);
void main()
{
  int i;
  printf("\nenter the no of processes\n");
  scanf("%d",&n);
  printf("enter burst time for each process\n");
  for(i=0;i<n;i++)
     {
    scanf("%d",&bt[i]);
    p[i]=i;
   }
    printf("\n FCfS algorithm \n");
    WT_TAT(&FCFS_tat,&FCFS_wt);
    printf("\n\nToatal turn around time :%d",FCFS_tat);
    printf("\n average turn around time :%d",FCFS_tat);
    printf("\n total waitng time :%d",FCFS_wt);
    printf("\naverge waiting time :%d",FCFS_wt);
}
int WT_TAT(int*a,int*b)
 {
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
  for(i=0;i<n;i++)
   {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
  }
  *b=tot_wt;
  printf("\n PROCESS\t\tBURST TIME\tTURN AROUND TIME \tWAITING TIME");
  for(i=0;i<n;i++)
    
       printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
        return 0;
}
