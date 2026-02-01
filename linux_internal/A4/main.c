#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void set_lock(int fd, int type) {
    struct flock lock;
    lock.l_type = type;    // F_WRLCK for write lock, F_UNLCK for unlock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;        // Lock entire file

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        exit(1);
    }
}

void print_primes(int fd) {
    char buffer[256];
    int count = 0;
    for (int num = 2; num <= 15; num++) {
        int is_prime = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            count += sprintf(buffer + count, "%d ", num);
        }
    }
    buffer[count] = '\n';
    write(fd, buffer, count + 1);
}

void print_fibonacci(int fd) {
    char buffer[256];
    int count = 0;
    int a = 0, b = 1;
    count += sprintf(buffer + count, "%d ", a);
    
    for (int i = 1; i < 10; i++) {
        count += sprintf(buffer + count, "%d ", b);
        int temp = a + b;
        a = b;
        b = temp;
    }
    buffer[count] = '\n';
    write(fd, buffer, count + 1);
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        printf("Insufficient arguments\n");
        printf("Usage:- %s filename\n", argv[0]);
        return 1;
    }

    // Open file
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) { // Parent process
        // Lock file
        printf("PARENT PROCESS: locked file\n");
        set_lock(fd, F_WRLCK);

        // Write to file
        printf("PARENT PROCESS: writing to file %s\n", argv[1]);
        print_primes(fd);

        // Unlock file
        set_lock(fd, F_UNLCK);
        printf("PARENT PROCESS: unlocked file\n");

        wait(NULL); // Wait for child to complete
    }
    else { // Child process
        // Lock file (will wait if parent has it locked)
        printf("CHILD PROCESS: locked file\n");
        set_lock(fd, F_WRLCK);

        // Write to file
        printf("CHILD PROCESS: writing to file %s\n", argv[1]);
        print_fibonacci(fd);

        // Unlock file
        set_lock(fd, F_UNLCK);
        printf("CHILD PROCESS: unlocked file\n");
    }

    close(fd);
    return 0;
}
