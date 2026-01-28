#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int main() {
    int indexBlock[MAX_BLOCKS]; // The index block stores pointers to file blocks
    int n, i;

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    if (n > MAX_BLOCKS) {
        printf("Maximum blocks exceeded!\n");
        return 1;
    }

    printf("Enter the block numbers for the file:\n");
    for (i = 0; i < n; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &indexBlock[i]);
    }

    printf("\nSimulating Indexed File Allocation...\n");
    printf("Index Block contains pointers to blocks:\n");
    for (i = 0; i < n; i++) {
        printf("Index[%d] -> Block %d\n", i, indexBlock[i]);
    }

    // Accessing the file
    int accessBlock;
    printf("\nEnter the block number to access (0 to %d): ", n - 1);
    scanf("%d", &accessBlock);

    if (accessBlock >= 0 && accessBlock < n) {
        printf("Accessing file: Index[%d] points to Block %d\n", accessBlock, indexBlock[accessBlock]);
    } else {
        printf("Invalid block number!\n");
    }

    return 0;
}
