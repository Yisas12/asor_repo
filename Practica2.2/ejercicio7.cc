#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
using namespace std;

int main(){
  mode_t mask = umask(027);
  int fichero =  open("ejer5.txt", O_CREAT | O_RDONLY, 0777);


  return 1;
}
