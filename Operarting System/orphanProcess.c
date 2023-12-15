#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int pid=fork();
    if(pid==0){
        sleep(5);
        printf("\nchild process running\n");
        printf("pid: %d\n",getpid());
        printf("parent pid:%d \n",getppid());
    }
    else{
        printf("parent process running\n");
        printf("pid: %d\n",getpid());
        exit(0);
    }
    return 0;
}