#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "board.h"


char * grid[10][10];
//Sample coordinates for testing purposes
char answer_coors[17][2] = {{'B','2'},
			    {'C','2'},
			    {'D','2'},
			    {'B','5'},
			    {'B','6'},
			    {'B','7'},
			    {'B','8'},
			    {'B','9'},
			    {'E','5'},
			    {'E','6'},
			    {'E','7'},
			    {'G','2'},
			    {'H','2'},
			    {'I','2'},
			    {'I','0'},
			    {'J','0'}};

void initialize_grid(){

  //Sets everything up as blank at first
  for (int r = 0; r < 10; r++){
    for (int c = 0; c < 10; c++){
      &grid[r][c] = '~';
    }
  }
  //Where ship parts are
  for (int i = 0; i < 17; i++){
    int num_coor = answer_coors[i][0] - 'A';
    printf("Answer coordinates: %c %c",answer_coors[i][0],answer_coors[i][1]);
  }
}

void print_grid(){
} 

char ** get_ship_coors(){
  int fd = open("alphaCoords.txt",O_RDONLY);
  char * buffer = malloc(sizeof(char)*25);
  int result = read(fd,buffer,sizeof(char)*25);
  char ** ans = calloc(256,5);
}
int hit_detection(char * coors){
  if (strlen(coors) != 2){
    printf("Invalid command: Not even the right size! \n Valid commands could include: A9, B6, C4, F6");
  }
  int letter = get_letter(coors);
  int number = get_number(coors);
  for (int i = 0; i < 17; i++){
  }
}

int main(){
  initalize_grid();
  return 0;
}
