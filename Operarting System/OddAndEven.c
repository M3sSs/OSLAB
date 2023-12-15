#include <stdio.h>
#include <unistd.h>
int main(){
    int n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[n],even_sun=0,odd_sum=0;
    printf("\nEnter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int pid=fork();
    if(pid==0){
        for(int i=0;i<n;i++){
            if(a[i]%2!=0){
                odd_sum+=a[i];
            }
        }
        printf("odd sum=%d\n",odd_sum);
        printf("pid: %d \n",getpid());
        printf("\nParent PID: %d\n",getppid());
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                even_sun+=a[i];
            }
        }
        printf("\neven sum=%d\n",even_sun);
        printf("pid: %d\n",getpid());
    }
    return 0;
}