#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
  int socket_fd;
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    printf("error: cannot create socket\n");
    return -1;
  }

  printf("client socket file descriptor: %d\n", socket_fd);

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(8080);
  server.sin_addr.s_addr = htonl(INADDR_ANY);

  if (connect(socket_fd, (struct sockaddr*) &server, sizeof(server)) == -1) {
    printf("error: fail to connect server\n");
    close(socket_fd);
    return -1;
  }

  printf("success to connect server\n");

  char buffer[BUFFER_SIZE];

  ssize_t readden = recv(socket_fd, buffer, BUFFER_SIZE, 0);
  if (readden < 0) {
    printf("error: fail to receive messages\n");
    close(socket_fd);
    return -1;
  }

  printf("message: %s\n", buffer);

  return 0;
}
