#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>

// thread routine
void *hello(void *vargp) {
    printf("hello, world\n");
    return NULL;
}

int main(int argc, char *argv[]) { 
    pthread_t tid;
    // create a thread to run hello
    pthread_create(&tid, NULL, hello, NULL);
    pthread_join(tid, NULL);
    exit(0);
}
