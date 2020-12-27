#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
using namespace std;

#define S_IWUSR 0000200

int main(int argc, char **argv){

  char *h = getenv("HOME");
  char *pipe = strcat(h, "/pipe");
  int p = mkfifo(pipe, 0777);
  int fd = open(pipe, O_WRONLY);

 // ofstream out;

  write(fd, argv[1], strlen(argv[1]));

  close(fd);
  
  return 1;
}
