#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;  // No allocation initially

    for (int i = 0; i < n; i++) {  // For each process
        for (int j = 0; j < m; j++) {  // Find the first fit block
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;  // Allocate block j to process i
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;  // No allocation initially

    for (int i = 0; i < n; i++) {  // For each process
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {  // Find the best fit block
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;  // Allocate block bestIdx to process i
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation\n");
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    // Make copies of blockSize array as we modify it in each strategy
    int blockSizeCopy[m];
    
    for (int i = 0; i < m; i++) blockSizeCopy[i] = blockSize[i];
    firstFit(blockSizeCopy, m, processSize, n);

    for (int i = 0; i < m; i++) blockSizeCopy[i] = blockSize[i];
    bestFit(blockSizeCopy, m, processSize, n);

    return 0;
}
