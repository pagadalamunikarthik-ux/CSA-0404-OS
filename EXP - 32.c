#include <stdio.h>

int main() {
    int n, m, i, j;
    
    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    int frames[m];     // memory frames
    int recent[m];     // stores "last used time" for each frame
    for (i = 0; i < m; i++)
        frames[i] = -1;    // initialize frames as empty
    for (i = 0; i < m; i++)
        recent[i] = 0;

    int page_faults = 0;

    printf("\nPage Replacement Process:\n");
    printf("Page\tFrames\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in frames (Page Hit)
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                recent[j] = i;  // Update last used time
                break;
            }
        }

        if (!found) {
            int lru_index = 0;
            int min_recent = recent[0];

            // Find Least Recently Used frame
            for (j = 0; j < m; j++) {
                if (frames[j] == -1) { // empty frame found
                    lru_index = j;
                    break;
                }
                if (recent[j] < min_recent) {
                    min_recent = recent[j];
                    lru_index = j;
                }
            }

            // Replace the LRU page
            frames[lru_index] = pages[i];
            recent[lru_index] = i;
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
