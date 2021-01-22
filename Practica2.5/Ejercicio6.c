#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char**argv){

  struct addrinfo hints;
  struct addrinfo *res;

  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC; //Coger direcciones IPv4 y Ipv6
  hints.ai_socktype = SOCK_STREAM; //Tipo de socket TCP
  hints.ai_flags = AI_PASSIVE; // node == NULL

  int socket = socket(res->ai_family, res->ai_socktype, 0);
  bind(socket, res->ai_addr, res->ai_addrlen);
  
  freeaddrinfo(res);

  listen(socket, 5);

  struct sockaddr_storage cliente;
  socklen_t cliente_len = sizeof(cliente);

  char buffer[81];
  int cli_sd;
  char host[NI_MAXHOST];
  
   char serv[NI_MAXSERV];
  ssize_t c;


  while(1){
    cli_sd = accept(socket,(struct sockaddr *) &cliente, &cliente_len);

    while (1) {
      getnameinfo((struct sockaddr *)&cliente, cliente_len, host, NI_MAXHOST, s$
      printf("Conexión desde %s:%s\n", host, serv);
      c = recv(cli_sd, buffer, 80, 0);
      buffer[c] = '\0';

      if ((buffer[0] == 'Q') && (c == 2)) {
        printf("Conexión terminada\n");
        break;
      }
      send(cli_sd, buffer, c, 0);
    }
 }
  close(cli_sd);

  return 0;
}
