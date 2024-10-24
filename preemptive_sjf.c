#include <stdio.h>

int main() {
    int n, i, time = 0, smallest, count = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], rt[n], p_done[n];//rt is remaining time
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        p_done[i] = 0;
    }
    
    while (count < n) {
        smallest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && p_done[i] == 0 && (smallest == -1 || rt[i] < rt[smallest]))
                smallest = i;
        }
        
        if (smallest == -1)
            time++;
        else {
            rt[smallest]--;
            time++;
            if (rt[smallest] == 0) {
                p_done[smallest] = 1;
                count++;
                printf("Process %d finished at time %d\n", smallest + 1, time);
            }
        }
    }
    return 0;
}