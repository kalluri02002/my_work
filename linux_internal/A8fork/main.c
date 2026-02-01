#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    // Creating first child process
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child1 with PID %d created\n", getpid());
        sleep(5);
        exit(0);
    }

    // Creating second child process
    pid2 = fork();
    if (pid2 == 0) {
        printf("Child2 with PID %d created\n", getpid());
        sleep(5);
        exit(0);
    }

    // Creating third child process
    pid3 = fork();
    if (pid3 == 0) {
        printf("Child3 with PID %d created\n", getpid());
        sleep(5);
        exit(0);
    }

    // Parent process waits for all children to terminate
    waitpid(pid1, &status, 0);
    printf("Child1 with PID %d terminated with code %d\n", pid1, WEXITSTATUS(status));

    waitpid(pid2, &status, 0);
    printf("Child2 with PID %d terminated with code %d\n", pid2, WEXITSTATUS(status));

    waitpid(pid3, &status, 0);
    printf("Child3 with PID %d terminated with code %d\n", pid3, WEXITSTATUS(status));

    printf("Parent process exiting.\n");
    return 0;
}

