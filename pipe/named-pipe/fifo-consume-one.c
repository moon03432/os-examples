#include <fcntl.h>
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {

    if (argc != 2) {
        printf("usage: %s <pipe>\n", argv[0]);
        return 1;
    }

    const char *pipe = argv[1];
    
    char buffer[2];

    memset(buffer, '\0', sizeof(buffer));

    int pipe_fd = open(pipe, O_RDONLY);
    if (pipe_fd == -1) {
        printf("error: cannot open pipe: %s\n", pipe);
        return 1;
    }
    
    read(pipe_fd, buffer, 1);
    close(pipe_fd);

    printf("%s\n", buffer);

    return 0;
}