#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int stop = 0;

void acciones(int senal){
  if(senal == SIGUSR1) stop = 1;
}

int main(int argc, char **argv){

  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGUSR1);
  sigprocmask(SIG_UNBLOCK, &mask, NULL);
  struct sigaction accion;

  sigaction(SIGUSR1, NULL, &accion);
  accion.sa_handler = acciones;
  sigaction(SIGUSR1, &accion, NULL);

  int segundos = atoi(argv[1]);
  int i = 0;
   while(i < segundos && stop == 0){
    i++;
    sleep(1);
  }

  if(stop == 0) unlink(argv[0]);

  return 1;
}
