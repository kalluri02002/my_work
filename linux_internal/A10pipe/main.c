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
    if (argc < 6) {
        printf("Error: %s\n", (argc == 1) ? "No arguments passed" : "Insufficient arguments passed");
        printf("Usage: %s <command1> '|' <command2> '|' <command3>\n", argv[0]);
        return 1;
    }

    // Check for two pipe symbols
    int pipe_count = 0;
    int pipe1_index = 0, pipe2_index = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            pipe_count++;
            if (pipe_count == 1) pipe1_index = i;
            else if (pipe_count == 2) pipe2_index = i;
        }
    }
    if (pipe_count != 2) {
        printf("Error: Exactly two pipe symbols '|' are required\n");
        printf("Usage: %s <command1> '|' <command2> '|' <command3>\n", argv[0]);
        return 1;
    }

    // Create two pipes
    int pipe1[2], pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid1, pid2, pid3;

    // First child process
    pid1 = fork();
    if (pid1 == 0) {
        close(pipe1[0]);    // Close unused read end
        close(pipe2[0]);    // Close second pipe read
        close(pipe2[1]);    // Close second pipe write
        
        dup2(pipe1[1], STDOUT_FILENO);  // Redirect stdout to pipe1
        close(pipe1[1]);

        char *cmd1_args[MAX_ARGS];
        char command1[100] = "";
        for (int i = 1; i < pipe1_index; i++) {
            strcat(command1, argv[i]);
            if (i < pipe1_index - 1) strcat(command1, " ");
        }
        split_command(command1, cmd1_args);

        execvp(cmd1_args[0], cmd1_args);
        perror("execvp failed for command1");
        exit(1);
    }

    // Second child process
    pid2 = fork();
    if (pid2 == 0) {
        close(pipe1[1]);    // Close unused write end
        close(pipe2[0]);    // Close second pipe read
        
        dup2(pipe1[0], STDIN_FILENO);   // Read from pipe1
        dup2(pipe2[1], STDOUT_FILENO);  // Write to pipe2
        close(pipe1[0]);
        close(pipe2[1]);

        char *cmd2_args[MAX_ARGS];
        char command2[100] = "";
        for (int i = pipe1_index + 1; i < pipe2_index; i++) {
            strcat(command2, argv[i]);
            if (i < pipe2_index - 1) strcat(command2, " ");
        }
        split_command(command2, cmd2_args);

        execvp(cmd2_args[0], cmd2_args);
        perror("execvp failed for command2");
        exit(1);
    }

    // Third child process
    pid3 = fork();
    if (pid3 == 0) {
        close(pipe1[0]);    // Close first pipe read
        close(pipe1[1]);    // Close first pipe write
        close(pipe2[1]);    // Close unused write end
        
        dup2(pipe2[0], STDIN_FILENO);   // Read from pipe2
        close(pipe2[0]);

        char *cmd3_args[MAX_ARGS];
        char command3[100] = "";
        for (int i = pipe2_index + 1; i < argc; i++) {
            strcat(command3, argv[i]);
            if (i < argc - 1) strcat(command3, " ");
        }
        split_command(command3, cmd3_args);

        execvp(cmd3_args[0], cmd3_args);
        perror("execvp failed for command3");
        exit(1);
    }

    // Parent process
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // Wait for all children
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
