#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_LENGTH 100

typedef struct {
    int id;
    char name[50];
} Record;

int main() {
    Record file[MAX_RECORDS];
    int n = 0;  // Number of records currently in file
    int choice;

    while (1) {
        printf("\n--- Sequential File Allocation ---\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Access a Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: // Add record
                if (n >= MAX_RECORDS) {
                    printf("File is full!\n");
                    break;
                }
                printf("Enter Record ID: ");
                scanf("%d", &file[n].id);
                getchar();
                printf("Enter Name: ");
                fgets(file[n].name, sizeof(file[n].name), stdin);
                file[n].name[strcspn(file[n].name, "\n")] = '\0'; // Remove newline
                n++;
                printf("Record added successfully.\n");
                break;

            case 2: // Display all records
                printf("\nAll Records in File:\n");
                for (int i = 0; i < n; i++) {
                    printf("Record %d -> ID: %d, Name: %s\n", i + 1, file[i].id, file[i].name);
                }
                break;

            case 3: // Access a specific record (sequential access)
                if (n == 0) {
                    printf("No records in file!\n");
                    break;
                }
                int access_id;
                printf("Enter Record ID to access: ");
                scanf("%d", &access_id);

                printf("\nAccessing record sequentially...\n");
                int found = 0;
                for (int i = 0; i < n; i++) {
                    printf("Reading Record %d -> ID: %d, Name: %s\n", i + 1, file[i].id, file[i].name);
                    if (file[i].id == access_id) {
                        found = 1;
                        printf("Record with ID %d found.\n", access_id);
                        break; // Stop after reaching the desired record
                    }
                }
                if (!found)
                    printf("Record with ID %d not found.\n", access_id);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
