#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
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

  if (fcntl(socket_fd, F_SETFL, O_NONBLOCK) < 0) {
    printf("error: failed to set socket non blocking\n");
    return -1;
  }

  char buffer[BUFFER_SIZE];
  ssize_t readden;

  while ((readden = recv(socket_fd, buffer, BUFFER_SIZE, 0)) < 0) {
    if (errno == EAGAIN || errno == EWOULDBLOCK) {
        printf("empty message\n");
        sleep(1);
    } else {
        printf("error: failed to read pipe\n");
        return -1;
    }
  }

  printf("message: %s\n", buffer);
  close(socket_fd);

  return 0;
}
