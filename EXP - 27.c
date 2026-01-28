#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    char dirname[100];
    DIR *dir;
    struct dirent *entry;

    // Ask user for directory name
    printf("Enter directory path to list files (use . for current directory): ");
    scanf("%s", dirname);

    // Open the directory
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Cannot open directory");
        exit(1);
    }

    printf("\nFiles in directory '%s':\n", dirname);

    // Read entries and print file/directory names
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(dir);

    return 0;
}
