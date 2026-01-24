#include <stdio.h>

int main() {
    int frames[10], pages[20];
    int no_of_frames, no_of_pages;
    int i, j, k = 0, page_faults = 0;
    int found;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string:\n");
    for (i = 0; i < no_of_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for (i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < no_of_pages; i++) {
        found = 0;

        // Check if page already exists
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page not found, replace using FIFO
        if (!found) {
            frames[k] = pages[i];
            k = (k + 1) % no_of_frames;
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
