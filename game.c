#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include "boardgen.c"


int main(){
  printf("Welcome!  Please insert text file formatted like this: \n");
  printf("5,[startingsquare],[V/H]\n");
  printf("4,[startingsquare],[V/H]\n");
  printf("3,[startingsquare],[V/H]\n");
  printf("3,[startingsquare],[V/H]\n");
  printf("2,[startingsquare],[V/H]\n");
  return 0;
}