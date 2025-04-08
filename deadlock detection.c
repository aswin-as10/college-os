#include<stdio.h>
int alloc[30][30],max[30][30],avail[30],req[30][30],n,r,i,k,j,work[30];
void input(){
    printf("\nenter the no of process");
    scanf("%d",&n);
    printf("enter the no of resources");
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
void display(){
    printf("\nallocation matrix\n");
    for(i=0;i<n;i++){
      for(j=0;j<r;j++)
         printf("\t%d",alloc[i][j]);
       printf("\n");
     }
    printf("\nmax matrix\n");
    for(i=0;i<n;i++){
       for(j=0;j<r;j++)
          printf("\t%d",max[i][j]);
       printf("\n");
    }
    printf("\navailable matrix\n");
    for(j=0;j<r;j++)
      printf("\t%d",avail[j]);
   
      
}
void requestmatrix(){
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
           req[i][j]=max[i][j]-alloc[i][j];}}
           printf("\nrequest matrix\n");
     for(i=0;i<n;i++){
        for(j=0;j<r;j++){
             printf("\t%d",req[i][j]);}
             printf("\n");}
}
void deadlock(){
  int finish[30]={0},flag=1;
  requestmatrix();
  for(j=0;j<r;j++){
      work[j]=avail[j];
  }
  while(flag==1){
      flag=0;
      for(i=0;i<n;i++){
        if(finish[i]==0){
            int c=0;
            for(j=0;j<r;j++){
                if(req[i][j]<=work[j]){
                    c++;
                }
            }
            if(c==r){
                for(k=0;k<r;k++){
                    work[k]+=alloc[i][k];
                }
                finish[i]=1;
                flag=1;
            }
        }
      }
  }
  int c1=0;
  for(i=0;i<n;i++){
    if(finish[i]==1){
        c1++;
    }
  }
  if(c1==n){
    printf("\nthere is no deadlock occur");
  }
  else{
    printf("\ndeadlock occur");
    printf("\ndeadlocked process are :\n");
    for(i=0;i<n;i++){
        if(finish[i]==0){
            printf("\tp%d",i);
        }
    }
  }

}

int main(){
    printf("BANKERS ALGORITHM");
    input();
    display();
    deadlock();
    return 0;
}

