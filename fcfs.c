#include <stdio.h>

struct Process {
    int id, at, bt, ct;  // id = process number, at = arrival time, bt = burst time, ct = completion time
};

void sortByArrivalTime(struct Process proc[], int n) {
    int i, j;
    struct Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].at > proc[j].at) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

int main() {
    int n, i, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process proc[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        proc[i].id = i + 1;
        scanf("%d %d", &proc[i].at, &proc[i].bt);
    }

    sortByArrivalTime(proc, n);  // Sort processes by arrival time

    for (i = 0; i < n; i++) {
        if (time < proc[i].at) time = proc[i].at;  // If CPU is idle, jump to arrival time
        time += proc[i].bt;  // Add burst time
        proc[i].ct = time;   // Completion time for the process
        printf("Process %d finished at time %d\n", proc[i].id, proc[i].ct);
    }

    return 0;
}
