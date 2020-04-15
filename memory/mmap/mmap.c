#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char * argv[]) {

    if (argc != 2) {
      printf("usage: %s <filename>\n", argv[0]);
      return EXIT_FAILURE;
    }

    int fd, nread;
    struct stat sb;
    char *mapped;

    // open file
    if((fd = open(argv[1], O_RDWR)) < 0){
      perror("open");
    }   

    // fstat
    if((fstat(fd, &sb)) == -1 ){
      perror("fstat");
    }   
     
    // mmap: map file into memory and return pointer of the memory
    if((mapped = mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == (void*) -1) {
      perror("mmap") ;
    }   
     
    // modify a character and synchronize to disk file
    mapped[20] = '9';
    if((msync((void *)mapped, sb.st_size, MS_SYNC)) == -1){
      perror("msync");
    }
      
    // free memory area
    if((munmap((void *)mapped, sb.st_size)) == -1){
      perror("munmap");  
    }   
                 
    return 0;
}
