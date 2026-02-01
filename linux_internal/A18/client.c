#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 5001
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 32

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int num1, num2;
    char operator;

    // Get input
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);
    printf("Enter arithmetic operator: ");
    scanf(" %c", &operator);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Server socket creation failed");
        exit(1);
    }
    printf("INFO: Created server socket\n");

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Server connection failed");
        exit(1);
    }
    printf("SUCCESS: Server connection successful\n");

    // Send data
    sprintf(buffer, "%d %d %c", num1, num2, operator);
    send(server_socket, buffer, strlen(buffer), 0);

    // Receive result
    recv(server_socket, buffer, BUFFER_SIZE, 0);
    printf("RESULT: %s\n", buffer);

    // Cleanup
    close(server_socket);
    return 0;
}
