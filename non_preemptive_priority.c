#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], pr[n], p_done[n];
    for (i = 0; i < n; i++) {
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        p_done[i] = 0;
    }

    int time = 0, count = 0, highest;
    while (count < n) {
        highest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && p_done[i] == 0 && (highest == -1 || pr[i] < pr[highest]))
                highest = i; 
        }

        if (highest == -1)
            time++;
        else {
            time += bt[highest];
            p_done[highest] = 1;
            count++;
            printf("Process %d finished at time %d\n", highest + 1, time);
        }
    }

    return 0;
}