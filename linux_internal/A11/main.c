#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMDS 10
#define MAX_ARGS 20

void execute_command(char *cmd[], int in_fd, int out_fd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (in_fd != 0) {
            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
        }
        if (out_fd != 1) {
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
        }
        execvp(cmd[0], cmd);
        perror("execvp failed");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Error: No arguments passed, provide at least one pipe or more\n");
        fprintf(stderr, "Usage: %s <command1> '|' <command2> ['|' <command3> ...]\n", argv[0]);
        exit(1);
    }
    
    char *commands[MAX_CMDS][MAX_ARGS];
    int cmd_count = 0;
    
    int arg_index = 1;
    int cmd_index = 0;
    
    while (arg_index < argc) {
        if (strcmp(argv[arg_index], "|") == 0) {
            commands[cmd_count][cmd_index] = NULL;
            cmd_count++;
            cmd_index = 0;
        } else {
            commands[cmd_count][cmd_index++] = argv[arg_index];
        }
        arg_index++;
    }
    commands[cmd_count][cmd_index] = NULL;
    cmd_count++;
    
    int pipes[MAX_CMDS - 1][2];
    for (int i = 0; i < cmd_count - 1; i++) {
        pipe(pipes[i]);
    }
    
    for (int i = 0; i < cmd_count; i++) {
        int in_fd = (i == 0) ? 0 : pipes[i - 1][0];
        int out_fd = (i == cmd_count - 1) ? 1 : pipes[i][1];
        
        execute_command(commands[i], in_fd, out_fd);
        
        if (i > 0) close(pipes[i - 1][0]);
        if (i < cmd_count - 1) close(pipes[i][1]);
    }
    
    for (int i = 0; i < cmd_count; i++) {
        wait(NULL);
    }
    
    return 0;
}

