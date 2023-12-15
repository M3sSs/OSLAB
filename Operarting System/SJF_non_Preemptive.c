#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct process {
    int pid, at, bt, st, ct, tat, wt, rt, cpt;
} pro;

int main() {
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;

    int n;
    printf("\nenter number of processes: ");
    scanf("%d", &n);
    pro p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].cpt = 0;
        printf("\nenter arrival time and burst time for process %d:   ", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }
    int completed = 0;
    int current_t = 0;
    int mn = INT_MAX; // Initialize mn with a large value
    int prev = 0;

    while (completed != n) {
        int idx = -1;
        // For finding out the process with the minimum bt up till the current time
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_t && p[i].cpt == 0) {
                if (p[i].bt < mn) {
                    idx = i;
                    mn = p[i].bt;
                } else if (p[i].bt == mn && idx != -1 && p[i].at < p[idx].at) {
                    idx = i;
                    mn = p[i].bt;
                }
            }
        }
        // If a process with the minimum bt is found
        if (idx != -1) {
            // Process found and scheduled
            p[idx].st = current_t;
            p[idx].ct = p[idx].st + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;

            total_turnaround_time += p[idx].tat;
            total_waiting_time += p[idx].wt;
            total_response_time += p[idx].rt;
            total_idle_time += p[idx].st - prev;

            p[idx].cpt = 1;
            completed++;

            current_t = p[idx].ct;
            prev = current_t;
        }
        // If no process with the minimum bt is found up till the current time
        else {
            current_t++;
        }
        mn = INT_MAX; // Reset mn for the next iteration
    }

    printf("\n\n");
    printf("#P\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
}
