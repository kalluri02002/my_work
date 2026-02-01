#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define SHM_SIZE 1024
#define FIFO_PATH "/tmp/myfifo"

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int pipefd[2];
    pid_t pid;
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *shm = (char *)shmat(shmid, NULL, 0);

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {  // Parent Process
        close(pipefd[0]);  // Close reading end of the pipe
        char input[SHM_SIZE];

        printf("Enter a string: ");
        fgets(input, SHM_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        write(pipefd[1], input, strlen(input) + 1);
        close(pipefd[1]);  // Close writing end

        int fifo_fd = open(FIFO_PATH, O_RDONLY);
        if (fifo_fd == -1) {
            perror("Failed to open FIFO");
            exit(1);
        }

        char output[SHM_SIZE];
        read(fifo_fd, output, sizeof(output));
        printf("Final output from FIFO: %s\n", output);
        close(fifo_fd);
        unlink(FIFO_PATH);

    } else {  // Child Process
        close(pipefd[1]);  // Close writing end
        char buffer[SHM_SIZE];

        read(pipefd[0], buffer, sizeof(buffer));
        close(pipefd[0]);  // Close reading end

        to_uppercase(buffer);
        strcpy(shm, buffer);  // Write to shared memory
        printf("Child Process (uppercase): %s\n", shm);

        shmdt(shm);
        exit(0);
    }

    return 0;
}

