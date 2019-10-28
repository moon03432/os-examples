#include <stdio.h>
#include <sys/stat.h>

int main(int argc, const char *argv[]) {
    int res = mkfifo("/Users/moon/Workspace/Linux/system-call/fifo", 0777);
    if (res == 0)
        printf("FIFO file created\n");

    return 0;
}