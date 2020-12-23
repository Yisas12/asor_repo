#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

int main(int argc, char **argv){

  if(execvp(argv[1], argv+1) == -1)perror("No se ha ejecutado");

  cout << "El comando terminó de ejecutarse\n";

  return 1;
}
