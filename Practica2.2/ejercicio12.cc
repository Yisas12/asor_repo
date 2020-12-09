  GNU nano 2.3.1            File: ejercicio12.cc                                

#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  int file = open(argv[1], O_CREAT | O_RDWR, 0777);

  if(file == -1){
    cout << "No se ha podido abrir el archivo\n";
    return -1;
  }

  int file2 = dup2(file, 1);
  cout << "Redirigido a "<< argv[1] << "\n";
  dup2(file2, file);

  return 1;
}
                               [ Read 19 lines ]
^G Get Help  ^O WriteOut  ^R Read File ^Y Prev Page ^K Cut Text  ^C Cur Pos
^X Exit      ^J Justify   ^W Where Is  ^V Next Page ^U UnCut Text^T To Spell
