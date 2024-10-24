#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_PHILOSOPHERS 5

int chopstick[NUM_PHILOSOPHERS] = {0};

void think(int philosopher_id){
    printf("Philosopher %d is thinking.\n",philosopher_id);
    sleep(1);
}

void eat(int philosopher_id){
    printf("Philosopher %d is eating.\n",philosopher_id);
    sleep(1);
}

void philosopher(int philosopher_id){
    int left_chopstick = philosopher_id;
    int right_chopstick = (philosopher_id+1)%NUM_PHILOSOPHERS;

    while(1){
        think(philosopher_id);

        if(chopstick[left_chopstick] == 0 && chopstick[right_chopstick] == 0){
            chopstick[left_chopstick] = 1;
            chopstick[right_chopstick] = 1;
            eat(philosopher_id);
            chopstick[left_chopstick] = 0;
            chopstick[right_chopstick] = 0;
        }else{
            printf("Philosopher %d is waiting for chopsticks.\n",philosopher_id);
        }
        sleep(1);
    }
}

int main(){
    int i;
    int pid[NUM_PHILOSOPHERS];

    for(i = 0;i<NUM_PHILOSOPHERS;i++){
        pid[i] = fork();
        if(pid[i] == 0){
            philosopher(i);
            exit(0);
        }
    }
    for(i = 0;i<NUM_PHILOSOPHERS;i++){
        wait(NULL);
    }

    return 0;
}
