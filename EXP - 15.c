#include <stdio.h>

int main() {
    int records[20], n, i;
    int start_address = 1000;   // starting memory location

    printf("Enter number of records: ");
    scanf("%d", &n);

    printf("Enter size of each record:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &records[i]);
    }

    printf("\nSequential File Allocation\n");
    printf("Record No\tSize\tPhysical Address\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\n", i + 1, records[i], start_address);
        start_address += records[i];   // next record stored sequentially
    }

    printf("\nAccessing records sequentially:\n");
    for (i = 0; i < n; i++) {
        printf("Reading Record %d\n", i + 1);
    }

    return 0;
}
