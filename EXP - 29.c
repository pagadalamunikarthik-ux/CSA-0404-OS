#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty;   // Counts empty slots
sem_t full;    // Counts full slots
pthread_mutex_t mutex;  // Protects buffer

// Producer function
void* producer(void* arg) {
    int item, i;
    for (i = 0; i < 10; i++) {  // Produce 10 items
        item = i + 1;

        sem_wait(&empty);  // Wait for empty slot
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer produced: %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);   // Signal that buffer has item

        sleep(1);  // Simulate time to produce
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int item, i;
    for (i = 0; i < 10; i++) {  // Consume 10 items
        sem_wait(&full);   // Wait for full slot
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumer consumed: %d at index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);  // Signal that buffer has empty slot

        sleep(2);  // Simulate time to consume
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    // Initialize semaphore and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy semaphore and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
