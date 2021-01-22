#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Memset,

#include <sys/types.h> //getaddrinfo, socket, bind
#include <sys/socket.h> //getaddrinfo, socket, bind


#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h> //getaddrinfo,

#include <time.h>

int main(int argc, char **argv){
  struct addrinfo hints;
  struct addrinfo *res, *it;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  //socket
  int socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  
   if (bind(socket, res->ai_addr, res->ai_addrlen) != 0) {
    printf("ERROR: No se ha podido ejecutar el bind.");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(result);

  signal(SIGCHLD, hler);

  char buffer[2];
  
   char host[NI_MAXHOST];
  char server[NI_MAXSERV];

  struct sockaddr_storage cliente;
  socklen_t cliente_length = sizeof(client_addr);
  int i = 0;
  int status;
  
  for (i = 0; i < 2; i++){
    pid_t pid;
    pid = fork();

    if (pid == 0) {
      while(1){
        ssize_t bytes = recvfrom(socket, buffer, 2, 0, (struct sockaddr *) &cli$
        buffer[1] = '\0';

        printf("%i bytes de %s:%s y su pid es %d\n", bytes, host, server, getpi$

        time_t tiempo = time(NULL);
        struct tm *tm = localtime(&tiempo);
        size_t max;
        char arr[50];

        if(buffer[0] == 't'){
          size_t bytesT = strftime(arr, max, "%I:%M:%S %p", tm);
          arr[bytesT]='\0';
          sendto(socket, arr, bytesT, 0, (struct sockaddr *) &cliente, cliente_$

        }
        else if(buffer[0]=='d'){
          size_t bytesT = strftime(arr, max, "%Y-%m-%d", tm);
          arr[bytesT] = '\0';
          sendto(socket, arr, bytesT, 0, (struct sockaddr *) &cliente, cliente_$


         }
        else if(buffer[0] == 'q'){
          printf("Salir\n");
          exit(0);
           }else printf("Comando incorrecto\n");

      }
    }
    else pid = wait(&status);
  }
  
  return 0;
}

        
