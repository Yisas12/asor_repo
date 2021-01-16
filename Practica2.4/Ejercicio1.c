#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argv, char** argc){


  int fd[2];
  int p = pipe(fd);

  if(fork()==-1){
    perror("ERROR");
    return 1;
  }
  else if(fork==0){ //hijo
    dup(fd[0]);
    close(fd[1]);
    close(fd[0]);
    execlp(argc[3], argc[3], argc[4]);
  }
  else{ //padre
    dup(fd[1]);
    close(fd[1]);
    close(fd[0]);
    execlp(argc[1], argc[1], argc[2]);
  }

}
