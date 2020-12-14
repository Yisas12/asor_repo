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
  
 if(cerrojo.l_type == F_UNLCK){ //si cerrojo desbloqueado
    cerrojo.l_type = F_WRLCK;
    cerrojo.l_whence = SEEK_SET;
    cerrojo.l_start = 0;
    cerrojo.l_len = 0;
    cerrojo.l_pid = getpid();
   
    if(fcntl(file, F_GETLK, cerrojo) == -1){
      close(file);
      return 1;
    }else cout << "Cerrojo de escritura creado\n";

    time_t tim = time(NULL);

    struct tm *tm = localtime(&tim);

    char buffer[1024];

    sprintf (buffer, "Hora: %d:%d\n", tm->tm_hour, tm->tm_min);
    write(file, &buffer, strlen(buffer));

    sleep(30);

    cerrojo.l_type = F_WRLCK;
    cerrojo.l_whence = SEEK_SET;
    cerrojo.l_start = 0;
    cerrojo.l_len = 0;
    cerrojo.l_pid = getpid();
    }
  close(file);

  return 1;
}


