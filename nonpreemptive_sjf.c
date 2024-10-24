#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], p_done[n];
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        p_done[i] = 0;
    }

    int time = 0, count = 0, shortest;
    while (count < n) {
        shortest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && p_done[i] == 0 && (shortest == -1 || bt[i] < bt[shortest]))
                shortest = i;
        }

        if (shortest == -1)
            time++;
        else {
            time += bt[shortest];
            p_done[shortest] = 1;
            count++;
            printf("Process %d finished at time %d\n", shortest + 1, time);
        }
    }

    return 0;
}
