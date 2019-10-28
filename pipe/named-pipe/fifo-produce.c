#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {

    printf("-> main\n");

    if (argc != 3) {
        printf("usage: %s <pipe> <message>\n", argv[0]);
        return 1;
    }

    const char *pipe_path = argv[1];
    const char *buffer = argv[2];
    int pipe_fd;
    int res;
    // int open_mode = O_WRONLY;

    if (access(pipe_path, F_OK) == -1) {
        printf("error: cannot access pipe: %s\n", pipe_path);
        return 1;
    }

    printf("succeeded to access pipe\n");

    pipe_fd = open(pipe_path, O_WRONLY);
    if (pipe_fd == -1) {
        fprintf(stderr, "error: failed to open pipe\n");
        exit(EXIT_FAILURE);
    }

    printf("succeeded to open pipe\n");

    res = write(pipe_fd, buffer, strlen(buffer));
    if (res == -1) {
        fprintf(stderr, "error: failed to write on pipe\n");
        exit(EXIT_FAILURE);
    }
    printf("succeeded to write pipe\n");
    close(pipe_fd);

    exit(EXIT_SUCCESS);

}