#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <fcntl.h>
#include <string>
using namespace std;

int main(int argc, char **argv){

  int c = system(argv[1]);
  int longitud = argc - 1;
  
  //calculamos el tamaño del comando
  /*for(int i = 1; i < argc;i++){
    longitud += strlen(argv[i]) + 1;
    char *com = malloc(sizeof(char)*longitud); //reservamos memoria
    strcpy(com, ""); //lo copiamos
  }*/

//juntamos todos los argumentos
  /*for(int i = 1; i < argc; i++){
    strcat(com, argv[i]);
     strcat(com, " ");
  }*/

  if(c==-1)perror("Error comando");

  cout << "El comando terminó de ejecutarse\n";

  return 1;
}
