#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#include <unistd.h>

#define SHM_SIZE 1024

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *shm = (char *)shmat(shmid, NULL, 0);

    printf("Enter the string: ");
    fgets(shm, SHM_SIZE, stdin);
    shm[strcspn(shm, "\n")] = '\0'; // Remove newline

    to_uppercase(shm);
    printf("Writing to shared memory: %s\n", shm);

    sleep(13); // Give time for Process 2 to read and modify the data

    printf("Reading from shared memory: %s\n", shm);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

