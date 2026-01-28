#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    char write_data[50] = "Hello, this is a UNIX file management test.";
    char read_data[50];

    // 1. Create/Open a file
    // Use a safe path: Linux: /tmp/testfile.txt, Windows: testfile.txt
    fd = open("/tmp/testfile.txt", O_CREAT | O_RDWR, 0666);  
    // For Windows, use: fd = open("testfile.txt", O_CREAT | O_RDWR, 0666);

    if (fd < 0) {
        perror("File could not be opened");
        exit(1);
    }
    printf("File opened successfully. FD = %d\n", fd);

    // 2. Write data to file
    if (write(fd, write_data, sizeof(write_data)) < 0) {
        perror("Error writing to file");
        close(fd);
        exit(1);
    }
    printf("Data written to file.\n");

    // 3. Move file pointer to beginning
    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("Error seeking file");
        close(fd);
        exit(1);
    }

    // 4. Read data from file
    if (read(fd, read_data, sizeof(read_data)) < 0) {
        perror("Error reading file");
        close(fd);
        exit(1);
    }
    printf("Data read from file: %s\n", read_data);

    // 5. Close file
    if (close(fd) < 0) {
        perror("Error closing file");
        exit(1);
    }
    printf("File closed successfully.\n");

    // 6. Delete file
    if (unlink("/tmp/testfile.txt") == 0) {  
        // For Windows, use: unlink("testfile.txt");
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }

    return 0;
}
