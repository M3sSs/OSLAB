#include <stdio.h>
#include <stdlib.h>
struct FCFS
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;

    int rt;
    int st;
};
int compare(const void *p1, const void *p2)
{
    int a = ((struct FCFS *)p1)->at;
    int b = ((struct FCFS *)p2)->at;
    if (a < b)
        return -1;
    else
        return 1;
}
int main()
{
    int n;
    float swt = 0, stat = 0;
    float cu = 0;
    float awt = 0, atat = 0;
    int sbt = 0;
    float srt = 0, art = 0;
    float thput = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);
    struct FCFS p[n];
    for (int i = 0; i < n; i++)
    {

        printf("For Process %d: ", i + 1);
        p[i].pid = i + 1;
        printf("Enter the value of AT and BT: ");
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    qsort((void *)p, n, sizeof(struct FCFS), compare);
    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].at + p[i].bt;
        }

        else if (p[i - 1].ct <= p[i].at)
        {
            p[i].st = p[i].at;
            p[i].ct = p[i].at + p[i].bt;
        }

        else
        {
            p[i].st = p[i - 1].ct;
            p[i].ct = p[i - 1].ct + p[i].bt;
        }
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sbt += p[i].bt;
        swt += p[i].wt;
        stat += p[i].tat;
        p[i].rt = p[i].wt;
        srt += p[i].rt;
    }

    awt = swt / n;
    atat = stat / n;
    art = srt / n;
    float max;
    for (int i = 0; i < n; i++)
    {
        max = 0;
        if (p[i].ct > max)
        {
            max = p[i].ct;
        }
    }
    thput = n / max;
    cu = (sbt / max) * 100;
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt,
               p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    printf("\nAvg Response Time : %f\nAvg Turn Around Time : %f\n", art,
           atat);
    printf("Avg Waiting Time : %f\nThroughput : %f\nCPU utilization : %f",
           awt, thput, cu);
    return 0;
}