#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SHM_SIZE 1024
#define FIFO_PATH "/tmp/myfifo"

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666);
    char *shm = (char *)shmat(shmid, NULL, 0);

    char buffer[SHM_SIZE];
    strcpy(buffer, shm);
    printf("Process 2 (read from SHM): %s\n", buffer);

    reverse_string(buffer);

    mkfifo(FIFO_PATH, 0666);
    int fifo_fd = open(FIFO_PATH, O_WRONLY);
    if (fifo_fd == -1) {
        perror("Failed to open FIFO");
        exit(1);
    }

    write(fifo_fd, buffer, strlen(buffer) + 1);
    printf("Process 2 (writing to FIFO): %s\n", buffer);

    close(fifo_fd);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

