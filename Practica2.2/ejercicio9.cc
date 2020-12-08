#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
using namespace std;

int main(int argc, char **argv){
  struct stat estado;
  int intstat = stat(argv[1], &estado);

  cout << minor(estado.st_dev) << " " << major(estado.st_dev) << "\n";
  cout << estado.st_ino << "\n";
  cout << estado.st_mode << "\n";
  cout << estado.st_atime << "\n";
  return 1;
}
