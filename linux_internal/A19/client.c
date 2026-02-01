#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 5001
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

struct CommandPacket {
    char command[100];
    int executions;
};

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    char buffer[BUFFER_SIZE];
    struct CommandPacket pkt;

    // Create UDP socket
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Get user input
    printf("Enter any standard command: ");
    fgets(pkt.command, sizeof(pkt.command), stdin);
    pkt.command[strcspn(pkt.command, "\n")] = 0;  // Remove newline
    
    printf("Enter no. of times to be executed: ");
    scanf("%d", &pkt.executions);

    // Send command packet
    sendto(client_socket, &pkt, sizeof(pkt), 0,
          (struct sockaddr*)&server_addr, server_len);

    // Receive and display output
    int packet_num = 1;
    while (1) {
        int bytes_received = recvfrom(client_socket, buffer, BUFFER_SIZE, 0,
                                    (struct sockaddr*)&server_addr, &server_len);
        if (bytes_received < 0) {
            perror("Receive failed");
            continue;
        }

        // Check for EOF flag
        if (bytes_received == 1 && buffer[0] == '0') {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        printf("(%d bytes of %dth packet received from server, sending ack)\n",
               bytes_received, packet_num);

        // Send ACK
        char ack[] = "ACK";
        sendto(client_socket, ack, strlen(ack), 0,
              (struct sockaddr*)&server_addr, server_len);
        
        packet_num++;
    }

    close(client_socket);
    return 0;
}
