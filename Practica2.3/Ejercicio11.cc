#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
using namespace std;

int main(){

  sigset_t senal;

  //inicializamos y añadimos señales
  sigaddset(&senal, SIGINT);
  sigaddset(&senal, SIGTSTP);

  //bloqueamos
  sigprocmask(SIG_BLOCK, &senal, NULL);

  //dormimos el proceso
char *s = getenv("SLEEP_SECS");
  int segundos = atoi(s);
  sleep(segundos);

  sigset_t pendiente;

  //si recibimos la señal la eliminamos
  if(sigismember(&pendiente, SIGINT) == 1)sigdelset(&senal, SIGINT);
  if(sigismember(&pendiente, SIGTSTP) == 1) sigdelset(&senal, SIGTSTP);
   sigprocmask(SIG_UNBLOCK, &senal, NULL);

  return 1;
}
