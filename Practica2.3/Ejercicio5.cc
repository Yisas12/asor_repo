#include<iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
using namespace std;

int main(){

  cout << "PID: " << getpid() << "\n";
  cout << "PPID: " << getppid() << "\n";
  cout << "PIDGrupos: " << getsid(getpid()) << "\n";

  struct rlimit limit;
  cout << "Limit: " << limit.rlim_max << "\n";
  
  return 1;
}
