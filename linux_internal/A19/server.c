#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define SERVER_PORT 5001
#define BUFFER_SIZE 1024
#define OUTPUT_FILE "server_output.txt"

struct CommandPacket {
    char command[100];
    int executions;
};

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    FILE *fp;

    // Create UDP socket
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Server started with PID: [%d]\n", getpid());

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    while (1) {
        // Receive command packet
        struct CommandPacket pkt;
        int bytes_received = recvfrom(server_socket, &pkt, sizeof(pkt), 0,
                                    (struct sockaddr*)&client_addr, &client_len);
        if (bytes_received < 0) {
            perror("Receive failed");
            continue;
        }

        // Execute command and store output
        fp = fopen(OUTPUT_FILE, "w");
        if (!fp) {
            perror("File open failed");
            continue;
        }

        for (int i = 0; i < pkt.executions; i++) {
            FILE *cmd = popen(pkt.command, "r");
            if (!cmd) {
                perror("Command execution failed");
                continue;
            }
            
            while (fgets(buffer, BUFFER_SIZE, cmd) != NULL) {
                fputs(buffer, fp);
            }
            pclose(cmd);
        }
        fclose(fp);

        // Send file contents to client
        fp = fopen(OUTPUT_FILE, "r");
        if (!fp) {
            perror("File open failed");
            continue;
        }

        int packet_num = 1;
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
            sendto(server_socket, buffer, strlen(buffer), 0,
                  (struct sockaddr*)&client_addr, client_len);
            
            // Wait for ACK
            recvfrom(server_socket, buffer, BUFFER_SIZE, 0,
                    (struct sockaddr*)&client_addr, &client_len);
            packet_num++;
        }

        // Send EOF flag (0)
        char eof_flag = '0';
        sendto(server_socket, &eof_flag, 1, 0,
              (struct sockaddr*)&client_addr, client_len);

        fclose(fp);
    }

    close(server_socket);
    return 0;
}
