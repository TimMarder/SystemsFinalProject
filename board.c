#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "board.h"


char grid[10][10];
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
      grid[r][c] = '~';
    }
  }
 
  //Where ship parts are, give them a '@' instead.
  for (int i = 0; i < 5; i++){
    //printf("Answer coordinates: %c %c",answer_coors[i][0],answer_coors[i][1]);
    int letter_coor = answer_coors[i][0] - 'A';
    printf("%d, ",letter_coor);
    int num_coor = answer_coors[i][1] - '0'; 
    printf("%d",num_coor);
    printf("\n");
    grid[letter_coor][num_coor] = '@';
  }
}

//Prints out array.
void print_grid(){
  char letters[] = {'A','B','C','D','E','F','G','H','I','J'};
		    
  int row = 0;
  printf("0 1 2 3 4 5 6 7 8 9\n");
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
       printf("%c ",grid[i][j]);
    }
    printf("%c\n",letters[row]);
    row++;
  }
  return;
} 

char ** get_ship_coors(){
  int fd = open("alphaCoords.txt",O_RDONLY);
  char * buffer = malloc(sizeof(char)*25);
  int result = read(fd,buffer,sizeof(char)*25);
  char ** ans = calloc(256,5);
  return ans;
}
int hit_detection(char * coors){
  if (strlen(coors) != 2){
    printf("Invalid command: Not even the right size! \n Valid commands could include: A9, B6, C4, F6");
  }
  // int letter = get_letter(coors);
  // int number = get_number(coors);
  for (int i = 0; i < 17; i++){
  }
  return 0;
}
int get_letter(char* coor){
  char s= coor[0];
  return 0;
}
//Returns 0 if that area was already hit.
//Returns 1 if successful.
int modify_grid(char mark, char * attack){
  int letter = attack[0] - 'A';
  int number = attack[1] - '0';
  if (grid[letter][number] != '~'){
    return 0;
  }
  grid[letter][number] = mark;
  return 1;
}

int check_hit(char * attack){
  int letter = attack[0] - 'A';
  int number = attack[1] - '0';
  printf("Letter: %d\n Number: %d",letter,number);
  for (int i = 0; i < 17; i++){
    int letter_coor = answer_coors[i][0] - 'A';
    int num_coor = answer_coors[i][1] - '0';
    if (letter == letter_coor && number == num_coor){
      printf("Hit!\n");
      modify_grid('X',attack);
      return 1;
    }
  }
  printf("Miss!\n");
  modify_grid('O',attack);
  return 0;
}



int main(){
  initialize_grid();
  printf("\n\n\n");
  // print_grid();
  // check_hit("A0");
  //check_hit("B2");
  //modify_grid('A',"A0");
  print_grid();
  return 0;
}
