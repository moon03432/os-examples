#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // fork, pipe

#define MAXLINE 20

int main(int argc, const char *argv[]) {
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) != 0) {
        printf("error: failed to create pipe");
        return 1;
    }

    if ((pid = fork()) < 0) // error
        exit(1);
    else if (pid > 0) {     // parent: write to pipe
        close(fd[0]);
        write(fd[1], "hello world\n", 13);
    } else {                // child: read pipe
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }

    return 0;
}