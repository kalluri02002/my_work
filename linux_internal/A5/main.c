#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_status(pid_t pid) {
    char path[50], line[100];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Process %d cleared by init\n", pid);
        return;
    }
    for (int i = 0; i < 3 && fgets(line, sizeof(line), fp) != NULL; i++) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) { // Child process
        printf("A child created with pid %d\n", getpid());
        print_status(getpid());
        sleep(2); // Simulating execution
        printf("Child process is now a zombie.\n");
        exit(0);
    } else { // Parent process
        sleep(1);
        printf("Child process is running.\n");
        print_status(pid);
        sleep(3); // Allowing time for the child to become a zombie
        printf("Child process is now a zombie.\n");
        print_status(pid);
        sleep(5); // Parent exits, making child an orphan
        printf("Parent process exiting, orphaning the child.\n");
    }
    return 0;
}


