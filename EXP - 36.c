#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

// Define a structure for a disk block
typedef struct Block {
    int blockNumber;
    struct Block* next;
} Block;

// Define a structure for a file
typedef struct File {
    int fileId;
    Block* start;
    Block* end;
} File;

Block* createBlock(int blockNumber) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    newBlock->blockNumber = blockNumber;
    newBlock->next = NULL;
    return newBlock;
}

int main() {
    int n, i, blockNum;
    File file;
    
    printf("Enter File ID: ");
    scanf("%d", &file.fileId);

    file.start = NULL;
    file.end = NULL;

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter block number %d: ", i + 1);
        scanf("%d", &blockNum);

        Block* newBlock = createBlock(blockNum);

        if (file.start == NULL) {
            file.start = newBlock;
            file.end = newBlock;
        } else {
            file.end->next = newBlock;
            file.end = newBlock;
        }
    }

    // Display the linked blocks of the file
    printf("\nLinked File Allocation for File ID %d:\n", file.fileId);
    printf("File blocks: ");
    Block* temp = file.start;
    while (temp != NULL) {
        printf("%d", temp->blockNumber);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");

    // Access a specific block (simulate traversal)
    int accessBlock;
    printf("\nEnter a block number to access: ");
    scanf("%d", &accessBlock);

    temp = file.start;
    int found = 0;
    while (temp != NULL) {
        if (temp->blockNumber == accessBlock) {
            printf("Block %d found in file.\n", accessBlock);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found)
        printf("Block %d not found in file.\n", accessBlock);

    return 0;
}
