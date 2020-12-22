#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
using namespace std;

int main(){

  pid_t pid, sid;

  pid = fork();
  if(pid == -1){
    perror("error fork");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0){
    pid_t msid = setsid(); //creo sesión
    int dir = chdir("/tmp");

    cout << "PID: " << getpid() << "\n";
    cout << "PPID: " << getppid() << "\n";
  }
  else{
    cout << "PID: " << getpid() << "\n";
    cout << "PPID: " << getppid() << "\n";
  }

  return 1;
}
