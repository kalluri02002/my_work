#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10

// Function to split command string into arguments
int split_command(char *cmd, char *args[]) {
    int i = 0;
    char *token = strtok(cmd, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return i;
}

int main(int argc, char *argv[]) {
    // Check for proper number of arguments
    if (argc < 4) {
        printf("Error: %s\n", (argc == 1) ? "No arguments passed" : "Insufficient arguments passed");
        printf("Usage: %s <command1> '|' <command2>\n", argv[0]);
        return 1;
    }

    // Check if pipe symbol exists
    int pipe_found = 0;
    int pipe_index = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            pipe_found = 1;
            pipe_index = i;
            break;
        }
    }

    if (!pipe_found) {
        printf("Error: Pipe symbol '|' not found\n");
        printf("Usage: %s <command1> '|' <command2>\n", argv[0]);
        return 1;
    }

    // Create pipe
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid1, pid2;

    // First child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid1 == 0) { // First child
        // Close read end of pipe
        close(pipefd[0]);
        
        // Redirect stdout to pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Prepare command1 arguments
        char *cmd1_args[MAX_ARGS];
        char command1[100] = "";
        for (int i = 1; i < pipe_index; i++) {
            strcat(command1, argv[i]);
            if (i < pipe_index - 1) strcat(command1, " ");
        }
        split_command(command1, cmd1_args);

        // Execute command1
        execvp(cmd1_args[0], cmd1_args);
        perror("execvp failed for command1");
        exit(1);
    }

    // Second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid2 == 0) { // Second child
        // Close write end of pipe
        close(pipefd[1]);
        
        // Redirect stdin from pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Prepare command2 arguments
        char *cmd2_args[MAX_ARGS];
        char command2[100] = "";
        for (int i = pipe_index + 1; i < argc; i++) {
            strcat(command2, argv[i]);
            if (i < argc - 1) strcat(command2, " ");
        }
        split_command(command2, cmd2_args);

        // Execute command2
        execvp(cmd2_args[0], cmd2_args);
        perror("execvp failed for command2");
        exit(1);
    }

    // Parent process
    // Close both ends of pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both children to complete
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
