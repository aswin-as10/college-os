#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
    char *shared_memory;
    char A[100];
    int shmid;
    shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("\nkey of shared memory is id %d",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("\nprocess attached at %p",shared_memory);
    printf("\nenter some data to write at shared memory");
    read(0,A,100);
    strcpy(shared_memory,A);
    printf("\n you wrote is %s",shared_memory);

}





#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
    char *shared_memory;
    int shmid;
    shmid=shmget((key_t)1222,1024,0666);
    printf("\nkey of the shared meory is %d ",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("\nprocess battached at %p",shared_memory);
    printf("\ndata in shared memory is %s",shared_memory);
}
