#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int shared = 0;

void* process(void* arg) {
    pthread_mutex_lock(&mutex);   // Enter critical section

    shared++;
    printf("Thread %ld entered critical section. Shared value = %d\n",
           (long)arg, shared);

    pthread_mutex_unlock(&mutex); // Exit critical section
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, process, (void*)1);
    pthread_create(&t2, NULL, process, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
