#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(8080);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(server_fd, (struct sockaddr*) &server, sizeof(server));
  listen(server_fd, 128);
  printf("server socket file descriptor: %d\n", server_fd);
  for (;;) {
    int client_fd = accept(server_fd, NULL, NULL);
    printf("client socket file descriptor: %d\n", client_fd);
    sleep(5);
    char response[] = "HTTP/1.1 200 OK\nContent-Length: 13\nConnection: close\n\nHello, world!";
    for (int sent = 0; sent < sizeof(response); sent += send(client_fd, response+sent, sizeof(response)-sent, 0));
    close(client_fd);
  }
  return 0;
}
