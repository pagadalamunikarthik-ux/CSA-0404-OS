#include <stdio.h>
#include <stdlib.h>

int mutex = 1;      // Semaphore for readcount
int wrt = 1;        // Semaphore for writer
int readcount = 0;
int data = 10;      // Shared data

void reader() {
    --mutex;
    readcount++;
    if (readcount == 1)
        --wrt;     // First reader blocks writer
    ++mutex;

    printf("Reader reads data = %d\n", data);

    --mutex;
    readcount--;
    if (readcount == 0)
        ++wrt;     // Last reader releases writer
    ++mutex;
}

void writer() {
    --wrt;
    data = data + 5;
    printf("Writer writes data = %d\n", data);
    ++wrt;
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Reader");
        printf("\n2. Writer");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (mutex == 1)
                reader();
            else
                printf("Reader is waiting...\n");
            break;

        case 2:
            if (wrt == 1)
                writer();
            else
                printf("Writer is waiting...\n");
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
