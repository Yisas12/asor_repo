#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int contINT = 0;
int contSTP = 0;

void acciones(int s){
  if(s == SIGINT) contINT++;
  if(s == SIGTSTP) contSTP++;
}

int main(){

  struct sigaction accion;

  sigaction(SIGINT, NULL, &accion); //get handler
  accion.sa_handler = acciones;
  sigaction(SIGINT, &accion, NULL); //set sa_handler

  sigaction(SIGTSTP, NULL, &accion);
  accion.sa_handler=acciones;
  sigaction(SIGTSTP, &accion, NULL);

  sigset_t set;

  while(contSTP + contINT < 10){
  sigsuspend(&set);
  }

  cout << "INT: " << contINT << " STP: " << contSTP << "\n";

  return 1;
}
