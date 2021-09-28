#include <stdio.h>

int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    return 0;
}

int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = burst_time[i] + wait_time[i];
    return 0;
}

int completiontime(int proc[], int n, int tat[], int CT[]) {
    int time = 0;
    CT[0] = tat[0];
    for (int i = 1; i < n; i++) {
        time += tat[i];
        CT[i] = time;
    }
    return 0;
}

int Print(int proc[], int n, int burst_time[]) {
    int wait_time[n], tat[n], completion_time[n], total_wt = 0, total_tat = 0;
    int i;
    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);
    completiontime(proc, n, tat, completion_time);
    printf("Processes    Burst    Completion    Waiting    Turn around \n");
    for (i = 0; i < n; i++) {
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf("%-12d %-8d %-13d %-10d %-14d\n", i + 1, burst_time[i], completion_time[i], wait_time[i], tat[i]);
    }
    printf("Average waiting time = %f\n", (float) total_wt / (float) n);
    printf("Average turn around time = %f\n", (float) total_tat / (float) n);
    return 0;
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {50, 80000, 12};
    Print(processes, n, burst_time);
    return 0;
}
