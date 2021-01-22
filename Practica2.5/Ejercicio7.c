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

   if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0) {
      printf("ERROR: No se ha podido ejecutar el getaddrinfo.");
      exit(EXIT_FAILURE);
  }

  int socket = socket(res->ai_family, res->ai_socktype, 0);
  connect(socket,(struct sockaddr *)res->ai_addr, res->ai_addrlen);
  freeaddrinfo(res);


  char host[NI_MAXHOST];
  char server[NI_MAXSERV];
  char buffent[256];
  char buffout[256];
  ssize_t c;


  while (1) {
    c = read(0,buffout, 255);
    buffout[c] = '\0';
    send(socket,buffout, c, 0);
    if ((buffout[1] == 'q') && (c == 2)) {
      printf("Conexión terminada\n");
      break;
    }

    c = recv(socket, buffent, 255, 0);
    buffent[c] = '\0';
    printf("[OUT]:%s\n", buffent);
    }

  close(socket);
  return 0;
}
