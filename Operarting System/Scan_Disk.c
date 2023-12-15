#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Low 0
#define High 199
int main(){
    int n,seektime=0,head,dloc,temp,max;
    printf("\nEnter the number of sequence:   ");
    scanf("%d",&n);
    int seq[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    printf("\nEnter the position of head: ");
    scanf("%d",&head);
    seq[n]=head;
    n++;
    // sorting sequence in ascending order
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(seq[i]>seq[j]){
                temp=seq[i];
                seq[i]=seq[j];
                seq[j]=temp;
            }
        }
    }
    max=seq[n-1];
    // locate head in the queue
    for(int i=0;i<n;i++){
        if(head==seq[i]){
            dloc=i;
            break;
        }
    }
    printf("\nThe Scan Sequence is:  ");
    if(abs(head-Low)<=abs(head-High)){
        for(int j=dloc;j>=0;j--){
            printf("%d ",seq[j]);
        }
        for(int j=dloc+1;j<n;j++){
            printf("%d ",seq[j]);
        }
    }
    else{
        for(int j=dloc+1;j<n;j++){
            printf("%d ",seq[j]);
        }
        for(int j=dloc;j>=0;j--)
            printf("%d ",seq[j]);
    }
    seektime=head+max;
    printf("\nTotal Seek Time is %d\n",seektime);
    return 0;
}