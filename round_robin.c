#include <stdio.h>

void roundRobin(int processes[], int n, int bt[], int quantum) {
    int rem_bt[n], t = 0;
    for (int i = 0; i < n; i++) rem_bt[i] = bt[i];
    
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    printf("Process %d finished at time %d\n", i+1, t);
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }
}

int main() {
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burst_time[n];
    
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    
    roundRobin(processes, n, burst_time, quantum);
    
    return 0;
}
