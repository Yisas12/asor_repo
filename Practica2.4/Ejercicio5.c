#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){
  char *tub = "tuberia";
  mkfifo(tub, 0644);
  char *tub2 = "tuberia2";
  mkfifo(tub2, 0644);

  char buf[257];

  //abrimos tuberias 
  int p1 = open(tub, O_RDONLY | O_NONBLOCK);
  int p2 = open(tub2, O_RDONLY | O_NONBLOCK);

  int c, pAct;

  while(c != -1){
    fd_set con;
    FD_ZERO(&con);
    FD_SET(p1, &con);
    FD_SET(p2, &con);
    int nPAct;

    c = select((p1 < p2) ? p2 + 1 : p1 + 1, &con, NULL, NULL, NULL);

    if(c > 0){
      //pipe actual
      if(FD_ISSET(p1, &con)){
        nPAct = 1;
        pAct = p1;
      }
      else if(FD_ISSET(p2, &con)){
        nPAct = 2;
        pAct = p2;
      }

      ssize_t rSize = 256;
      while(rSize == 256){
       rSize = read(pAct, buf, 256);
       buf[rSize] = '\0';
       printf("tuberia %i: %s", nPAct, buf);
      }

      if(rSize != 256 && nPAct == 1){
        close(p1);
        p1 = open(tub, O_RDONLY | O_NONBLOCK);
        if(p1 == -1){
          perror("ERROR");
          close(p1);
          close(p2);
          return -1;
        }
      }
      else if(rSize != 256 && nPAct == 2){
        close(p2);
        p2 = open(tub2, O_RDONLY | O_NONBLOCK);
        if(p2 == -1){
          perror("ERROR");
          close(p1);
          close(p2);
          return -1;
        }
      }
    }
  }//while
  
  close(p1);
  close(p2);
  return 0;
}

