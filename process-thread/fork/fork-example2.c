#include <sys/types.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t pid;

	/* fork a child process */
    pid = fork();

	if (pid < 0) { /* error occurred */ 
		fprintf(stderr, "Fork Failed"); 
		return 1;
	} 
	else if (pid == 0) { /* child process */ 
		execlp("/bin/ls","ls",NULL);
	} 
	else { /* parent process */
        int status;
		/* parent will wait for the child to complete */ 
		wait(&status);
		printf("Child Complete with state %d", status);
	}

	return 0;
}
