#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i;
    int requests[100];
    int head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int seek_sequence[100];
    int total_seek_time = 0;
    int current_position = head;

    printf("\nProcessing FCFS Disk Scheduling...\n");
    printf("Head Movement:\n");

    for (i = 0; i < n; i++) {
        seek_sequence[i] = requests[i];
        int distance = abs(current_position - requests[i]);
        printf("Move from %d to %d with distance %d\n", current_position, requests[i], distance);
        total_seek_time += distance;
        current_position = requests[i];
    }

    printf("\nFCFS Seek Sequence: ");
    printf("%d ", head);
    for (i = 0; i < n; i++)
        printf("-> %d ", seek_sequence[i]);
    printf("\n");

    printf("Total Seek Time: %d\n", total_seek_time);
    printf("Average Seek Time: %.2f\n", (float)total_seek_time / n);

    return 0;
}
