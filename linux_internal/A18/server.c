#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 5001
#define BUFFER_SIZE 32

// Structure to hold operation result
struct Operation {
    char operator;
    int (*func)(int, int);
};

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }
int modulo(int a, int b) { return b != 0 ? a % b : 0; }

struct Operation operations[] = {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide},
    {'%', modulo}
};

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("INFO: created server socket\n");

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen
    listen(server_socket, 5);
    printf("LISTENING: server is listening\n");

    while (1) {
        // Accept connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("ACCEPTED: accepted a connection\n");

        // Receive data
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        int num1, num2;
        char operator;
        sscanf(buffer, "%d %d %c", &num1, &num2, &operator);
        printf("Client data: %d %d %c\n", num1, num2, operator);

        // Calculate result
        int result = 0;
        for (int i = 0; i < 5; i++) {
            if (operations[i].operator == operator) {
                result = operations[i].func(num1, num2);
                break;
            }
        }
        printf("Result is %d\n", result);

        // Send result
        sprintf(buffer, "%d", result);
        printf("Sending result to client...\n");
        send(client_socket, buffer, strlen(buffer), 0);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}
