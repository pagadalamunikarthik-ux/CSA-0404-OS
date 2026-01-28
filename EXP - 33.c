#include <stdio.h>

int main() {
    int n, m, i, j, k;

    // Input reference string
    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &m);

    int frames[m];
    for (i = 0; i < m; i++)
        frames[i] = -1;  // Initialize empty frames

    int page_faults = 0;

    printf("\nPage Replacement Process:\n");
    printf("Page\tFrames\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page already in frame (page hit)
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) { // Page fault occurs
            int replace_index = -1;
            int farthest = -1;

            // Check for empty frame first
            for (j = 0; j < m; j++) {
                if (frames[j] == -1) {
                    replace_index = j;
                    break;
                }
            }

            // If no empty frame, find optimal page to replace
            if (replace_index == -1) {
                for (j = 0; j < m; j++) {
                    int next_use = -1;
                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j]) {
                            next_use = k;
                            break;
                        }
                    }
                    if (next_use == -1) { // Not used again
                        replace_index = j;
                        break;
                    }
                    if (next_use > farthest) {
                        farthest = next_use;
                        replace_index = j;
                    }
                }
            }

            // Replace page
            frames[replace_index] = pages[i];
            page_faults++;
        }

        // Print current page and frame status
        printf("%d\t", pages[i]);
        for (j = 0; j < m; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        if (!found)
            printf("<-- Page Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
