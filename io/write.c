#include <unistd.h>

int main() {
    char buffer[] = "hello, world\n";
    write(STDOUT_FILENO, buffer, sizeof(buffer));
    _exit(0);
}
