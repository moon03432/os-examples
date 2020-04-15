#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>	// open, O_RDWR
#include <stdio.h>
#include <stdlib.h>	// printf
#include <unistd.h>	// close

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDWR);
    close(fd);

    return 0;
}
