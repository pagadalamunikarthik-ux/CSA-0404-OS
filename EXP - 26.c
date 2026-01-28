#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int choice;
    char filename[50];
    char data[100];
    
    while (1) {
        printf("\n--- File Management Operations ---\n");
        printf("1. Create & Write to File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter filename to create: ");
                scanf("%s", filename);
                getchar();
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    perror("Error creating file");
                    break;
                }
                printf("Enter data to write: ");
                fgets(data, sizeof(data), stdin);
                fprintf(fp, "%s", data);
                fclose(fp);
                printf("File created and data written successfully.\n");
                break;

            case 2:
                printf("Enter filename to read: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    perror("Error opening file");
                    break;
                }
                printf("File contents:\n");
                while (fgets(data, sizeof(data), fp) != NULL) {
                    printf("%s", data);
                }
                fclose(fp);
                break;

            case 3:
                printf("Enter filename to append: ");
                scanf("%s", filename);
                getchar();
                fp = fopen(filename, "a");
                if (fp == NULL) {
                    perror("Error opening file");
                    break;
                }
                printf("Enter data to append: ");
                fgets(data, sizeof(data), stdin);
                fprintf(fp, "%s", data);
                fclose(fp);
                printf("Data appended successfully.\n");
                break;

            case 4:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                if (remove(filename) == 0)
                    printf("File deleted successfully.\n");
                else
                    perror("Error deleting file");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
