#include <stdio.h>

int main() {
    int n, m, i, j, k;  // n = number of processes, m = number of resource types
    printf("Enter number of processes and resource types: ");
    scanf("%d %d", &n, &m);

    int Allocated[n][m], Maximum[n][m], Available[m], Need[n][m], Finish[n];
    
    // Input allocation matrix (currently allocated resources)
    printf("Enter Allocated Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &Allocated[i][j]);

    // Input maximum matrix (maximum demand of each process)
    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &Maximum[i][j]);

    // Input available resources (initial available resources in the system)
    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &Available[i]);

    // Calculate the Need matrix (Need = Maximum - Allocated)
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            Need[i][j] = Maximum[i][j] - Allocated[i][j];

    // Initialize Finish
    for (i = 0; i < n; i++) 
        Finish[i] = 0;  // Mark all processes as unfinished (0)

    // Banker's algorithm safety check
    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (Finish[i] == 0) {  // If the process is not finished
                for (j = 0; j < m; j++) {
                    if (Need[i][j] > Available[j])  // If the process cannot be satisfied
                        break;
                }

                if (j == m) {  // If all resources needed by process i can be allocated
                    // Simulate resource release by directly modifying Available
                    for (k = 0; k < m; k++)
                        Available[k] += Allocated[i][k];  // Add allocated resources to available
                    Finish[i] = 1;  // Mark the process as finished
                    found = 1;
                    count++;
                    printf("Process %d can safely execute.\n", i + 1);
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }
    printf("System is in a safe state.\n");
    return 0;
}
