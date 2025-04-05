#include<stdio.h>
int main(){
     int i,j,p,b,bsize[30],psize[30],allocation[30],bestinx;
     printf("\nenter the no of blocks and process");
     scanf("%d%d",&b,&p);
     printf("\nenter the process sizes");
     for(i=0;i<p;i++){
        scanf("%d",&psize[i]);
     }
     printf("\nenter the block sizes");
     for(j=0;j<b;j++){
        scanf("%d",&bsize[j]);
     }
     for(i=0;i<p;i++){
        allocation[i]=-1;
     }
     for(i=0;i<p;i++){
        bestinx=-1;
            for(j=0;j<b;j++){
                if(bsize[j]>=psize[i]){
                    if(bestinx==-1||bsize[j]<bsize[bestinx]){
                        bestinx=j;
                    }
                }
            }
        if(bestinx!=-1){
            allocation[i]=bestinx;
            bsize[bestinx]-=psize[i];
        }
     }
     printf("\nPROCESS\t\tSIZE\t\tBLOCKS");
     for(i=0;i<p;i++){
        printf("\np%d\t\t%d\t",i,psize[i]);
        if(allocation[i]!=-1)
            printf("\t%d\n",allocation[i]);
        else
           printf("\tnot allocated\n");
        }

}
