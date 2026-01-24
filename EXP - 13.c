#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[20], time[10];
    int no_of_frames, no_of_pages;
    int i, j, page_faults = 0, counter = 0;
    int found, pos;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string:\n");
    for (i = 0; i < no_of_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames and time
    for (i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < no_of_pages; i++) {
        found = 0;

        // Check if page already in frames
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        // If page fault
        if (!found) {
            pos = -1;

            // Check for empty frame
            for (j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, replace LRU page
            if (pos == -1) {
                pos = findLRU(time, no_of_frames);
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            page_faults++;
        }

        // Display frames
        printf("%d\t", pages[i]);
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
