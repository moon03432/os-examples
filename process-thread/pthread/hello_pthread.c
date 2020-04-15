#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// thread routine
void *hello(void *vargp) {
    printf("hello, world...\n");
    sleep(60);
    return NULL;
}

int main(int argc, char *argv[]) { 
    pthread_t tid;
    // create a thread to run hello
    pthread_create(&tid, NULL, hello, NULL);
    pthread_join(tid, NULL);
    exit(0);
}
