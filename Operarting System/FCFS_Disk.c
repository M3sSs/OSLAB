#include <stdio.h>
#include <math.h>
int main(){
    int n,seektime=0,head;
    printf("Enter the number of sequence:   ");
    scanf("%d",&n);
    int seq[n];
    printf("\nEnter the sequence: ");
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    printf("\nEnter the position of head: ");
    scanf("%d",&head);
    printf("\nThe FCFS sequence is:  ");
    for(int i=0;i<n;i++){
        printf("%d ",seq[i]);
        seektime+=abs(head-seq[i]);
        head=seq[i];
    }
    printf("\nTotal seektime=%d",seektime);
    return 0;
}