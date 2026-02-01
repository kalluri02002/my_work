#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// Method 1: Using signal handler
void sigchld_handler(int sig) {
    int status;
    pid_t pid = wait(&status);
    if (pid > 0) {
        printf("Child terminated with exit code %d.\n", WEXITSTATUS(status));
    }
}

int main() {
    printf("Executing Method 1:\n");
    signal(SIGCHLD, sigchld_handler);
    
    if (fork() == 0) {
        // Child process
        printf("Child process started.\n");
        exit(0);
    }
    // Parent process
    sleep(12); // Giving time for child to terminate
    
    return 0;

}
