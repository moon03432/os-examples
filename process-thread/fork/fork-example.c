#include <unistd.h>     // fork
#include <stdio.h>      // printf
#include <sys/types.h>  // pid_t

int main (){
    pid_t fpid; //fpid表示fork函数返回的值
    fpid = fork();
    
    if (fpid < 0) {
        printf("error in fork!");
        return 1;
    }
    
    if (fpid == 0) {
        printf("I am child. Process id is %d\n", getpid());
        printf("I am child. Process group id is %d\n", getpgrp());
    }
    else {
        printf("I am parent. My process id is %d, Child process id is %d\n", getpid(), fpid);
        printf("I am parent. Process group id is %d\n", getpgrp());
    }
    return 0;
}
