#include<stdio.h>
int max[100][100],alloc[100][100],need[100][100],avail[100],n,r;
void input();
void show();
void cal();
int main(){
    printf("BANKERS ALGORITHM");
    input();
    show();
    cal();
    return 0;
}
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
    printf("\nPROCESS\tALLOCATION\tMAX\tAVAILABLE\n");
    for(i=0;i<n;i++){
        printf("p[%d]\t",i);
        for(j=0;j<r;j++){
              printf("\t%d",alloc[i][j]);
        }
        printf("\t");
        for(j=0;j<r;j++){
            printf("\t%d",max[i][j]);
       }
       printf("\t");
       if(i==0){
           for (j=0;j<r;j++){
            printf("\t%d",avail[j]);
          }
       }
       printf("\n");
    }
}
void cal(){
    int finish[100]={0},c1=0,flag=1,i,j,k;
    for(i=0;i<n;i++)
      for(j=0;j<r;j++)
          need[i][j]=max[i][j]-alloc[i][j];
 
    while(flag==1){
        flag=0;
     for (i = 0; i < n; i++){
        if(finish[i]==0){
            int c=0;
            for(j=0;j<r;j++){
                if(need[i][j]<=avail[j]){
                   c++;
                }
            }
            if(c==r){
                for(int k=0;k<r;k++){
                   avail[k]=avail[k]+alloc[i][k];
                }
                finish[i]=1;
                printf("P%d->",i);
                flag=1;
            }
        }
      }
    
    }
    for(i=0;i<n;i++){
        if(finish[i]==1){
            c1++;
        }
    }
    if(c1==n){
        printf("\nthe system is in safe state");
    }
    else{
        printf("\nthe syatem is not in a safe state");
    }
}

    

