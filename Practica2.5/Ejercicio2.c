#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

  //creamos socket
  int socket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  //asignamos al socket la direccion de ai_addr
  if(bind(socket, res->ai_addr, res->ai_addrlen) != 0){
    printf("ERROR asignacion memoria");
    exit(EXIT_FAILURE);
  }
  
  freeaddrinfo(res);
  
  char buffer[2];
  char host[NI_MAXHOST];
  char server[NI_MAXSERV];

  struct sockaddr_storage cliente;
  socklen cliente_length = sizeof(cliente);

  while(1){

    ssize_t bytes = recvfrom(socket, buffer, 2, 0, (struct sockaddr *) &cliente, cliente_length);
    buffer[1]='\0';

    getnameinfo((struct sockaddr *) &cliente, cliente_length, host, NI_MAXHOST,server, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
    printf("%i bytes de %s:%s\n", bytes, host, server);

    time_t tiempo = time(NULL);
    struct tm *tm = localtime(&tiempo);
    size_t max;
    char arr[50];

    //hora
    if(buffer[0] == 't'){
      size_t bytesT = strftime(s, max, "%I:%M:%S %p", tm);
      arr[bytesT] = '\0';
      sendto(socket, arr, bytesT, 0, (struct sockaddr *) &cliente, cliente_length);

    }
     //fecha
    else if(buffer[0] == 'd'){
      size_t bytesT = strftime(arr, max, "%Y-%m-%d", tm);
      arr[bytesT] = '\0';
      sendto(socket, arr, bytesT, 0, (struct sockaddr *) &cliente, cliente_length);
 
    }
    //terminar proceso
    else if(buffer[0] == 'q'){
      printf("Salir\n");
      exit(0);
    }
    else printf("Comando no soportado\n");

  }

return 0;
}
