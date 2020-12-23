#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char **argv){

  pid_t pid;

  pid = fork();
  if(pid < 0){
    perror("error fork");
  }
  else if(pid == 0){
    pid_t msid = setsid();

    cout << "PID: " << getpid() << " PPID: " << getppid() << "\n";

    int st = open("/tmp/daemon.out", O_CREAT | O_RDWR, 00777);
    int err = open("/tmp/daemon.err", O_CREAT | O_RDWR, 00777);
    int ent = open("/dev/null", O_CREAT | O_RDWR, 00777);
    int st2 = dup2(st, 2);
    int err2 = dup2(err, 1);
    int ent2 = dup2(ent, 0);

    if(execvp(argv[1],argv + 1) == -1) perror("Error execvp");
  }
  else{
    cout << "PID: " << getpid() << "PPID: " << getppid() << "\n";
  }
  return 1;
}
