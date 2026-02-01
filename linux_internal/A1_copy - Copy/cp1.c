#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to copy contents from source_fd to dest_fd
int my_copy(int source_fd, int dest_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            return -1;
        }
    }
    if (bytes_read < 0) {
        perror("Error reading source file");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments\n");
        printf("Usage: ./my_copy [-p] source_file destination_file\n");
        return 1;
    }

    int preserve_permissions = 0;
    char *source_file, *dest_file;

    if (strcmp(argv[1], "-p") == 0) {
        if (argc < 4) {
            printf("Insufficient arguments\n");
            printf("Usage: ./my_copy [-p] source_file destination_file\n");
            return 1;
        }
        preserve_permissions = 1;
        source_file = argv[2];
        dest_file = argv[3];
    } else {
        source_file = argv[1];
        dest_file = argv[2];
    }

    // Open source file
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Check if destination file exists
    if (access(dest_file, F_OK) == 0) {
        char response;
        printf("File \"%s\" already exists. Do you want to overwrite? (Y/n): ", dest_file);
        scanf(" %c", &response);
        if (response == 'n' || response == 'N') {
            close(source_fd);
            printf("Operation aborted.\n");
            return 0;
        }
    }

    // Open/Create destination file
    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(source_fd);
        return 1;
    }

    // Copy file content
    if (my_copy(source_fd, dest_fd) < 0) {
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    // Preserve permissions if -p option is used
    if (preserve_permissions) {
        struct stat file_stat;
        if (fstat(source_fd, &file_stat) == 0) {
            chmod(dest_file, file_stat.st_mode);
        } else {
            perror("Error preserving permissions");
        }
    }

    // Close files
    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
    return 0;
}

