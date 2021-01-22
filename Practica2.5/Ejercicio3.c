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

  sendto(socket, argv[3], 2, 0, res->ai_addr, res->ai_addrlen);
  
   printf("%s\n", argv[3]);

  if(*argv[3] == 'd' || *argv[3] == 't'){
   char arr[50];
   ssize_t bytes = recvfrom(socket, arr, 50, 0, (struct sockaddr *) &cliente, &cliente_length);
   arr[bytes] = '\0';

   printf("%s\n", arr);
  }

  return 0;
}
