#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    int x=fork();
    if(x>0){
        printf("parent processs running\n");
        printf("id: %d\n",getpid());
        sleep(5);
        printf("parent pid: %d after sleep\n",getpid());
    }
    else if(x==0){
        sleep(10);
        printf("\nchild process running\n");
        printf("pid:%d\n",getpid());
        printf("child printing parent pid:%d\n",getppid());
    }
    return 0;
}