#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
using namespace std;

int main(){
  int fichero =  open("ejer5.txt", O_CREAT, 645);

 // if(fichero == -1) return errno;


  return 1;
}
