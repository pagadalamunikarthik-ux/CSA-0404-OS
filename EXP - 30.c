#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>  // for intptr_t

// Thread function
void* threadFunc(void* arg) {
    intptr_t id = (intptr_t)arg;  // cast pointer to integer
    printf("Thread %ld is running...\n", id);
    sleep(1);
    
    if (id == 2) {
        printf("Thread %ld exiting using pthread_exit()\n", id);
        pthread_exit((void*)id); // exit with value
    }

    return (void*)id;
}

int main() {
    pthread_t t1, t2;

    // 1. Create threads
    pthread_create(&t1, NULL, threadFunc, (void*)1);
    pthread_create(&t2, NULL, threadFunc, (void*)2);
    printf("Threads created successfully.\n");

    // 2. Check if threads are equal
    if (pthread_equal(t1, t2))
        printf("Threads t1 and t2 are equal.\n");
    else
        printf("Threads t1 and t2 are NOT equal.\n");

    // 3. Join threads
    void* retval;
    pthread_join(t1, &retval);
    printf("Thread t1 joined. Return value = %ld\n", (intptr_t)retval);

    pthread_join(t2, &retval);
    printf("Thread t2 joined. Return value = %ld\n", (intptr_t)retval);

    printf("Main thread exiting.\n");
    return 0;
}
