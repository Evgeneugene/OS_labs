#include <stdio.h>
typedef struct process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
    int ct;
    int wt;
    int tat;
} Process;

void avgTime(Process proc[], int n)
{
    int total_wt = 0, total_tat = 0;
    proc[0].wt = 0;
    proc[0].tat = proc[0].bt;
    proc[0].ct = proc[0].art + proc[0].tat;
    for(int i = 1; i < n; i++){
        if(proc[i].art < proc[i-1].ct){
            proc[i].wt = proc[i-1].ct - proc[i].art;
        }
        proc[i].tat = proc[i].wt + proc[i].bt;
        proc[i].ct = proc[i].art + proc[i].tat;
        printf("%d %d %d\n\n", proc[i].wt, proc[i].bt, proc[i].tat);
    }
    printf("%d %d %d\n\n", proc[0].wt, proc[0].bt, proc[0].tat);
    printf("Processes   Arrival   Burst   Completion    TurnAround    Waiting   \n");
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + proc[i].wt;
        total_tat = total_tat + proc[i].tat;
        printf("P%-10d %-9d %-7d %-13d %-13d %-9d\n", proc[i].pid, proc[i].art, proc[i].bt,
               proc[i].ct, proc[i].tat, proc[i].wt);
    }
    printf("Average waiting time = %f", (double)total_wt / (double)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
}
void initStruct(Process proc[], int n){
    for (int i = 0; i < n; i++){
        proc[i].tat = 0;
        proc[i].wt = 0;
        proc[i].ct = 0;
    }
}
int main()
{
    Process proc[] = {{ 1, 1, 4 }, { 2, 4, 6 }, { 3, 2, 10 },
                      { 4, 3, 10 }, {5, 4, 13}};
    int n = sizeof(proc) / sizeof(proc[0]);
    initStruct(proc, n);
    avgTime(proc, n);
    return 0;
}