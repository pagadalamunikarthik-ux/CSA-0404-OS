#include <stdio.h>

int predict(int pages[], int frames[], int n, int index, int frame_count) {
    int res = -1, farthest = index, i, j;

    for (i = 0; i < frame_count; i++) {
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        // If a page is not found in future
        if (j == n)
            return i;
    }

    // If all pages found in future, return the farthest one
    return (res == -1) ? 0 : res;
}

int main() {
    int frames[10], pages[20];
    int no_of_frames, no_of_pages;
    int i, j, page_faults = 0, found, pos;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string:\n");
    for (i = 0; i < no_of_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for (i = 0; i < no_of_frames; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < no_of_pages; i++) {
        found = 0;

        // Check if page already present
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page fault
        if (!found) {
            // Check for empty frame
            pos = -1;
            for (j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find optimal replacement
            if (pos == -1)
                pos = predict(pages, frames, no_of_pages, i + 1, no_of_frames);

            frames[pos] = pages[i];
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
