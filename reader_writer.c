#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int shared_data = 0;
int read_count = 0; // Number of active readers
bool write_flag = false; // Indicates if a writer is writing

void reader(int reader_id) {
    // Check if a writer is currently writing
    while (write_flag) {
        printf("Reader %d is waiting since a Writer is writing.\n", reader_id);
        sleep(1); // Simulate waiting
    }

    read_count++; // Increase the count of active readers
    printf("Reader %d is reading the shared data %d\n", reader_id, shared_data);

    read_count--; // Decrease the count after reading
}

void writer(int writer_id) {
    // Check if there are active readers or another writer
    while (read_count > 0 || write_flag) {
        printf("Writer %d is waiting because readers or another writer is active.\n", writer_id);
        sleep(1); // Simulate waiting
    }

    write_flag = true; // Set the write flag to indicate writing

    // Writing to shared data
    shared_data++;
    printf("Writer %d is writing to the shared data: %d\n", writer_id, shared_data);

    write_flag = false; // Reset the write flag after writing
}

int main() {
    int choice;
    int id = 1;

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. New Reader\n");
        printf("2. New Writer\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                reader(id);
                id++;
                break;
            case 2:
                writer(id);
                id++;
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice entered\n");
        }
    }

    return 0;
}
