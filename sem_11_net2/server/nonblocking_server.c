#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <assert.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void set_nonblock(int socket) {
    int flags = fcntl(socket, F_GETFL, 0);
    assert(flags != -1);
    fcntl(socket, F_SETFL, flags | O_NONBLOCK);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }


    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

	while (1) {
		printf("Server is listening on port %d\n", PORT);

		// Accept an incoming connection
    	if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    	    perror("Accept failed");
    	    close(server_fd);
    	    // exit(EXIT_FAILURE);
			continue;
		}

		set_nonblock(client_fd);

    	// Read data from the client
    	int valread = read(client_fd, buffer, BUFFER_SIZE);
    	printf("Client: %s\n", buffer);

    	// Send response to the client
    	const char *response = "Hello from server";
    	send(client_fd, response, strlen(response), 0);
    	printf("Response sent to client\n");

		shutdown(client_fd, SHUT_RDWR);
		close(client_fd);
	}

	shutdown(server_fd, SHUT_RDWR);
    close(server_fd);
    
}

