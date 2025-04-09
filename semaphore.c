#include<stdio.h>
#include<stdlib.h>
int mutex=1,empty=5,full=0,x=0;
int wait(int s){
   --s;
}
int signal(int s){++s;}
int producer(){
   mutex=wait(mutex);
   ++full;
   --empty;
   x++;
   printf("\nproduced item is %d ",x);
   mutex=signal(mutex);
}
int consumer(){

        mutex=wait(mutex);
        --full;
        ++empty;
        printf("\nconsumed item is %d",x);
        x--;
        mutex=signal(mutex);
}
int main()
{
int n,i;
printf("\n 1.press for producer" "\n press 2 for Consumer " "\n press 3 for exit");
while(1){
printf("\n enter your choice");
scanf("%d",&n);
switch(n)
{
  case 1:
    if(mutex==1&&empty!=0){
        producer();
    
    }   
    else 
      printf("\nbuffer is full");
    break;
  case 2:
     if(mutex==1&&full!=0){
        consumer();
     }
     else{
        printf("\nbuffer is empty");
     }
     break;
  case 3:
     return 0;

}
}
}
