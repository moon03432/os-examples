#include <fcntl.h>       // O_RDONLY
#include <stdio.h>       // printf
#include <sys/mman.h>    // shm_open, mmap
// #include <unistd.h>      // ftruncate

int main() {
     const int SIZE = 4096;
     const char *name = "OS";
     int shm_fd;
     void *ptr;
     shm_fd = shm_open(name, O_RDONLY, 0666);
     ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
     printf("%s", (char *)ptr);
     shm_unlink(name);
     return 0;
}
