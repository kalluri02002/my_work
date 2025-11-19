#include <fcntl.h>      // for open()
#include <unistd.h>     // for read(), write(), close()
#include <stdio.h>      // for perror()
#include <string.h>     // for strlen()
#include <stdlib.h>     // for exit()

int main() {
    int fd;
    char buffer[100];
    ssize_t bytes_written, bytes_read;

    // 1. Open a file for writing (create if not exists, truncate if exists)
    fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open for write");
        exit(EXIT_FAILURE);
    }

    // 2. Write data to the file
    const char *data = "Linux file operation using system calls.\n";
    bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Data written successfully (%ld bytes).\n", bytes_written);

    // 3. Close the file
    close(fd);

    // 4. Open the file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open for read");
        exit(EXIT_FAILURE);
    }

    // 5. Read data from the file
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0'; // Null terminate the buffer

    printf("Data read from file:\n%s", buffer);

    // 6. Close the file
    close(fd);

    return 0;
}
