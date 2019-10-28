#include <stdio.h>      // printf
#include <unistd.h>     // getpid
#include <sys/types.h>  // pid_t

int main(int argc, char const *argv[])
{
    pid_t pid = getpid();
    printf("pid: %d\n", pid);
    
    pid_t gpid = getpgrp();
    printf("process group id: %d\n", gpid);

  return 0;
}
