#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv){
  struct stat s;
  int intstat = stat(argv[1], &s);
  
  char* hard =(char*) malloc(sizeof(char)*(5 + strlen(argv[1])));
  char* sym = (char*)malloc(sizeof(char)*(5 + strlen(argv[1])));

  strcpy(hard, argv[1]);
  strcpy(sym, argv[1]);
  hard = strcat(hard, ".hard");
  sym = strcat(sym, ".sym");

  cout << hard << " " << sym << "\n";

  return 1;
}

