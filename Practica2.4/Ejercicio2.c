#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
  int p[2];
  int h[2];
  int msg="";
  char stop = '';
  int fd[2];

  pipe(p);
  pipe(h);

  if(fork() == -1){
    perror("ERROR");
    return 1;
  }
  else if(fork() == 0){
  close(p[1]);
    close(h[0]);
    for(size_t i = 0; i < 10; i++){
      ssize_t bytes = read(p[0], msg, 255);
      msg[bytes] = '\0';
      printf("Hijo recibido: %s\n", msg);
      sleep(1);
      if(i == 9) flag = 'q';
      write(h[1], &flag, 1);
    }
    }
  else{
    close(p[0]);
    close(h[1]);
    while(stop != 'q'){
      printf("%s\n", "Padre msg: ");
      ssize_t bytes = read(0, msg, 255);
      msg[bytes] = '\0';
      write(p[1], msg, 255);
      read(h[0], &flag, 1);
    }
    wait(NULL);
    close(fd[1]);
    close(fd[0]);
  }
}

