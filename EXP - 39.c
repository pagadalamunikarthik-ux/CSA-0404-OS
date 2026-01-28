#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, disk_size;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter disk request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size (maximum track number): ");
    scanf("%d", &disk_size);

    int left[n], right[n];
    int l = 0, r = 0;

    // Separate requests
    for (i = 0; i < n; i++) {
        if (req[i] < head)
            left[l++] = req[i];
        else
            right[r++] = req[i];
    }

    // Sort left and right arrays
    for (i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++)
            if (left[i] > left[j]) {
                int t = left[i];
                left[i] = left[j];
                left[j] = t;
            }

    for (i = 0; i < r - 1; i++)
        for (int j = i + 1; j < r; j++)
            if (right[i] > right[j]) {
                int t = right[i];
                right[i] = right[j];
                right[j] = t;
            }

    int total_seek = 0;
    int current = head;

    printf("\nC-SCAN Seek Sequence:\n");

    // Move towards higher end
    for (i = 0; i < r; i++) {
        printf("%d -> ", right[i]);
        total_seek += abs(right[i] - current);
        current = right[i];
    }

    // Move to end of disk
    total_seek += abs((disk_size - 1) - current);
    current = disk_size - 1;
    printf("%d -> ", current);

    // Jump to start of disk
    total_seek += (disk_size - 1);
    current = 0;
    printf("%d -> ", current);

    // Serve remaining requests
    for (i = 0; i < l; i++) {
        printf("%d -> ", left[i]);
        total_seek += abs(left[i] - current);
        current = left[i];
    }

    printf("END\n");

    printf("\nTotal Seek Time: %d\n", total_seek);
    printf("Average Seek Time: %.2f\n", (float)total_seek / n);

    return 0;
}
