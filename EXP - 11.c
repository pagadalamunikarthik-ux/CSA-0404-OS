#include <stdio.h>
#include <pthread.h>

// Function executed by thread 1
void* printNumbers(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread 1: %d\n", i);
    }
    return NULL;
}

// Function executed by thread 2
void* printLetters(void* arg) {
    for (char c = 'A'; c <= 'E'; c++) {
        printf("Thread 2: %c\n", c);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, printNumbers, NULL);
    pthread_create(&t2, NULL, printLetters, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread finished.\n");
    return 0;
}
