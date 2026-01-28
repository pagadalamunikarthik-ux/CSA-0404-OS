#include <stdio.h>

int main() {
    int nb, np;
    int block[20], process[20];
    int allocation[20];
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for (i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for (i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;   // Not allocated
    }

    // Worst Fit Allocation
    for (i = 0; i < np; i++) {
        int worst = -1;

        for (j = 0; j < nb; j++) {
            if (block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
