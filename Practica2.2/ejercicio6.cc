include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

int main(){
  mode_t mask = umask(027);
  int archivo = open("ejer6.txt", O_CREAT | O_RDONLY, 0777);

  return 1;
}

