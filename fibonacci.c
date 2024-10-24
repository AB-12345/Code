#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int *fibonacci;  // Shared array for Fibonacci sequence
int n;  // Number of Fibonacci numbers to generate

void* generateFibonacci(void* arg) {
    fibonacci[0] = 0;
    if (n > 1) fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    return NULL;
}

int main() {
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    fibonacci = (int*)malloc(n * sizeof(int));  // Allocate memory for Fibonacci sequence

    pthread_t fib_thread;
    pthread_create(&fib_thread, NULL, generateFibonacci, NULL);  // Create thread to generate Fibonacci sequence
    pthread_join(fib_thread, NULL);  // Wait for the child thread to finish

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    free(fibonacci);  // Free allocated memory
    return 0;
}
