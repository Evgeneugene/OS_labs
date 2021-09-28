#include <stdio.h>
typedef struct process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
} Process;

void waitingTime(Process proc[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
    int complete = 0, t = 0, minm = 999999;
    int shortest = 0, finish_time;
    int check = 0;
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
                (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }
        if (check == 0) {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = 999999;
        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}
void turnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
void completionTime(Process proc[], int n, int tat[], int ct[]){
    for (int i = 0; i < n; i++){
        ct[i] = proc[i].art + tat[i];
    }
}
void avgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0, ct[n];
    waitingTime(proc, n, wt);
    turnAroundTime(proc, n, wt, tat);
    completionTime(proc, n, tat, ct);
    printf("Processes   Arrival   Burst   Completion    TurnAround    Waiting   \n");
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("P%-10d %-9d %-7d %-13d %-13d %-9d\n", proc[i].pid, proc[i].art, proc[i].bt, ct[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %f", (double)total_wt / (double)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
}

int main()
{
    Process proc[] = {{ 1, 1, 4 }, { 2, 4, 6 }, { 3, 2, 10 },
                      { 4, 3, 10 }, {5, 4, 13}};
    int n = sizeof(proc) / sizeof(proc[0]);
    avgTime(proc, n);
    return 0;
}