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

int main (int argc, char**argv) {
  struct addrinfo hints;
  struct addrinfo *res, *it;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  int socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  
  freeaddrinfo(res);

  char buffer[2];
  char host[NI_MAXHOST];
  char server[NI_MAXSERV];

  struct sockaddr_storage cliente;
  socklen_t client_length = sizeof(client_addr);

  fd_set lect; //descriptor lectura
  int l = -1;
  
   while(1){
    while(l==-1){
      FD_ZERO(&lect); //vaciamos puntero
      FD_SET(socket, &lect); //metemos descriptor en socket
      FD_SET(0, &lect);  //metemos descr en entrada estandar
      l = select(socket+1, &lect, NULL, NULL, NULL);
    }

    time_t tiempo = time(NULL);
    struct tm *tm = localtime(&tiempo);
    size_t max;
    char arr[50];

    if(FD_ISSET(socket, &lect)){
      ssize_t bytes = recvfrom(socket, buffer, 2, 0, (struct sockaddr *) &clien$
      getnameinfo((struct sockaddr *) &cliente, cliente_length, host, NI_MAXHOS$
      printf("[RED] %i bytes de %s:%s\n", bytes, host, server);
      buffer[1] = '\0';

      if(buffer[0] == 't'){
        size_t bytesT = strftime(arr, max, "%I:%M:%S %p", tm);
         arr[bytesT] ) '\0';
        sendto(socket, arr, bytesT, 0, (struct sockaddr *) &cliente, cliente_le$

      }
      else if(buffer[0] == 'd'){
        size_t bytesT = strftime(arr, max, "%Y-%m-%d", tm);
        arr[bytesT]='\0';
        sendto(socket, arr, bytesT, 0, (struct sockaddr *) &cliente, cliente_le$

      }
      else if(buffer[0] == 'q'){
        printf("Salir\n");
        exit(0);
      }
      else{
	read(0, buffer, 2);
        printf("[Consola] %i bytes\n", 2);
        buffer[1] = '\0';

        if(buffer[0] =='t){
         size_t bytesT = strftime(arr, max, %I:%M:%S %p", tm);
          arr[bytesT] = '\0';
          printf("%s\n", arr);
        }
	else if(buffer[0] == 'd'){
          size_t bytesT = strftime(arr, max, "%Y-%m-%d", tm);
          arr[bytesT] = '\0';
          printf("%s\n", arr);
        }
        else if(buffer[0] == 'q'){
          printf("Salir\n");
          exit(0);
        }
	else printf("Comando incorrecto\n");
      }
    }
  return 0;
 }
        
