#include<iostream>
#include<string>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv){

 // cin >> argv[1];

  //prioridad del proceso
  int priority = getpriority(PRIO_PROCESS, 0);

  //politica de planificacion
 // int pid = atoi(argv[1]);
 
 int schedule = sched_getscheduler(PRIO_PROCESS);

  cout << priority << "\n";

  if(schedule == SCHED_OTHER) cout << "SCHED_OTHER\n";
  else if(schedule == SCHED_FIFO) cout << "SCHED_FIFO\n";
  else if(schedule == SCHED_RR) cout << "SCHED_RR\n";
  else if(schedule == SCHED_BATCH) cout << "SCHED_BATCH\n";
  else if(schedule == SCHED_IDLE) cout << "SCHED_IDLE\n";
  
  //maximo y minimo
  int max = sched_get_priority_max(schedule);
  int min = sched_get_priority_min(schedule);

  cout << "Maximo = " << max << "\n";
  cout << "Minimo = " << min << "\n";

  return 1;
}
