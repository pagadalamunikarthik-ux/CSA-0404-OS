#include <stdio.h>

int main() {
    int n, m, i, j, k;
    
    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &m);
    
    int frames[m];
    for (i = 0; i < m; i++)
        frames[i] = -1;  // Initialize empty frames
    
    int page_faults = 0;
    int index = 0; // To keep track of FIFO order
    
    printf("\nPage Replacement Process:\n");
    printf("Page\tFrames\n");
    
    for (i = 0; i < n; i++) {
        int found = 0;
        
        // Check if page is already in frames (Page hit)
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) { // Page fault occurs
            frames[index] = pages[i];
            index = (index + 1) % m; // FIFO replacement
            page_faults++;
        }
        
        // Print current page and frame status
        printf("%d\t", pages[i]);
        for (k = 0; k < m; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        if (!found)
            printf(" <-- Page Fault");
        printf("\n");
    }
    
    printf("\nTotal Page Faults: %d\n", page_faults);
    
    return 0;
}
