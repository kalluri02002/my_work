#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

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

    printf("Reading from shared memory: %s\n", shm);
    reverse_string(shm);
    printf("Writing to shared memory: %s\n", shm);

    shmdt(shm);
    return 0;
}

