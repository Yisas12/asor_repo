#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

  struct addrinfo hints;

  memset(&hints, 0, sizeof(struct addrinfo));

  hints.ai_family = AF_UNSPEC; //permitimos redes ipv4 e ipv6
  hints.ai_socktype = 0; //las direcciones del socket puede ser de varios tipo
  hints.ai_protocol = 0; //puede ser cualquier protocolo
  hints.ai_flags = AI_PASSIVE; //enlazar un socket que aceptará conexiones
  hints.ai_canonname = NULL; //especificado en el ejemplo del man
  hints.ai_addr = NULL; //especificado en el ejemplo del man
  hints.ai_next = NULL; //especificado en el ejemplo del man

  struct addrinfo *result, *iterator;

 int getinfo = getaddrinfo(argv[1], NULL, &hints, &result);
  if(getinfo != 0){
     printf("ERROR");
     exit(EXIT_FAILURE);
  }


  for(iterator = result; iterator != NULL; iterator = iterator->ai_next){
    if(iterator->ai_family == AF_INET){
      struct sockaddr_in *info = iterator->ai_addr;
      char ip[INET_ADDRSTRLEN + 1] = "";
      inet_ntop(AF_INET, &(info->sin_addr), ip, INET_ADDRSTRLEN + 1);
      //family, address, stringbuf, length
      printf("%s\t", ip);
    }
    else if(iterator->ai_family == AF_INET6){
      struct sockaddr_in6 *info6 = iterator->ai_addr;
      char ipv6[INET6_ADDRSTRLEN + 1] = "";
      inet_ntop(AF_INET6, &(info6->sin6_addr), ipv6, INET6_ADDRSTRLEN + 1);
      //family, address, stringbuf, length

      printf("%s\t", ipv6);
      }
   }

  printf("%i\t%i\t\n",iterator->ai_family, iterator->ai_socktype);
  freeaddrinfo(result);

  return 1;
}
