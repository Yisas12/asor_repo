  GNU nano 2.3.1            File: ejercicio15.cc                                

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  int file = open(argv[1], O_CREAT | O_RDWR, 0777);

  struct flock cerrojo;

  cerrojo.l_type = F_UNLCK;
  cerrojo.l_whence = SEEK_SET;
  cerrojo.l_start = 0;
  cerrojo.l_len = 0;
  cerrojo.l_pid = getpid();

                               [ Read 54 lines ]
^G Get Help  ^O WriteOut  ^R Read File ^Y Prev Page ^K Cut Text  ^C Cur Pos
^X Exit      ^J Justify   ^W Where Is  ^V Next Page ^U UnCut Text^T To Spell
