#include <stdio.h>
#include <unistd.h>
int main(){
    fork();
    printf("the process id:%d\n\n",getpid());
    return 0;
}