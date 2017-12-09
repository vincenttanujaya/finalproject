#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
  if(argc==1) chdir("/");
  else if(argc!=2) printf(1,"Needs 2 argumenrts\n");
  else if(chdir(argv[1])<0)
  {
    printf(1,"Failed to change directory\n");
  }

  exit();
}

