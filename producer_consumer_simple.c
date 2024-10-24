#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

void produce(int item) {
    if (count < BUFFER_SIZE) {
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced: %d\n", item);
    } else {
        printf("Buffer full, cannot produce\n");
    }
}

int consume() {
    if (count > 0) {
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed: %d\n", item);
        return item;
    } else {
        printf("Buffer empty, cannot consume\n");
        return -1;
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                produce(item);
                break;
            case 2:
                consume();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
