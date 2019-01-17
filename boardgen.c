#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


//5: Carrier
//4: Battleship
//3: Cruiser
//3: Submarine
//2: Destroyer

/*
Array_coors[3]:
[0] = Row count (A-J/0-9);
[1] = Column Count (0-9);
[2] = Orientation (0 = Horizontal, 1 = Vertical);
[3] = Length of Ship;
*/

char *grid_one[10][10];
char *grid_two[10][10];

void populate_grid(char *grid[10][10]){
  for(int r = 0; r < 10; r ++){
    for(int c = 0; c < 10; c ++){
      grid[r][c] = "~ ";
    }
  }
}

void print_grid(char *grid[10][10]){
  char val = 'A';
  printf("     0 1 2 3 4 5 6 7 8 9\n");
  printf("--------------------------\n");
  for(int r = 0; r < 10; r ++){
    printf(" %c | ", val);
    val ++;
    for(int c = 0; c < 10; c ++){
      printf("%s", grid[r][c]);
    }
    printf("\n");
  }
  printf("--------------------------\n");
  
}

int get_alpha_coor(char *coor){
  char s = coor[0];
  return s -'A';
}

int get_num_coor(char *coor){
  char s = coor[1];
  return s -'0';
}

int check_coor(char *coor){
  if(strlen(coor) != 2)
    return 0;
  else if(coor[0] < 'A' || coor[0] > 'J')
    return 0;
  else if(coor[1] < '0' || coor[1] > '9')
    return 0;
  else
    return 1;
}

char **get_ship_placement(){
  int fd = open("alphaCoords.txt", O_RDONLY);
  char *buffer = malloc(sizeof(char)*25);
  int result = read(fd, buffer, sizeof(char)*25);
  printf("%s\n", buffer);
  char **arr = calloc(256, 5);
  for(int i = 0; i < 5; i++){
    arr[i] = strsep(&buffer, "\n");
    printf("%s\t", arr[i]);
  }
  printf("\n");
  return arr;
}

void place_ships(){
  char **arr = get_ship_placement();
  for(int i = 0; i < 5; i ++){
    int a = get_alpha_coor(arr[i]);
    int n = get_num_coor(arr[i]);
    char orien = (arr[i])[2];
    int len = (arr[i])[3]-'0';
    if(orien == 'V'){
      for(int i = a; i < a +len; i++){
	grid_two[i][n] = "@ ";
      }
    }
    if(orien == 'H'){
      for(int i = n; i < n +len; i++){
	grid_two[a][i] = "@ ";
      }
    }
  }
}

int check_lose(){
  for(int r = 0; r < 10; r++){
    for(int c = 0; c < 10; c++){
      if(grid_two[r][c] == "@ "){
	//printf("DID NOT LOSE\n");
	return 0;
      }
    }
  }
  //printf("LOSE\n");
  return 1;
}

int give_coors(char * filename){
  int coordfile;
  char *coordinates = (char *)malloc(360);
  //coordfile  = open(filename, O_RDONLY);
  read(coordfile, coordinates, 360);
  close(coordfile);
  
  printf("%s",coordinates);  
}

int parse_args(char * coors){
      //Ship components:
      
      
      int alphagen(){
	return 0;
      }

      int betagen(){
      }
}

/*
int * command_handle(){
  //Ex: A4
  char * steve = calloc(100,sizeof(char));
  fgets(steve, 100, stdin);
  int horizontal = steve[0] - 40 + 2; //Numerical value = Unicode Char - 40 shifted 2   
  int vertical = steve[1] + 2; //Second value shifted 2
  int coors[2] = {horizontal,vertical};
  return coors;
}
*/

int main(int argc, int *argv[]){
  //int coors[5][2];
  //give_coors("alphaCoords.txt");
  printf("Welcome to Battleships!\n");
  populate_grid(grid_one);
  populate_grid(grid_two);
  print_grid(grid_one);
  print_grid(grid_two);
  get_ship_placement();
  place_ships();
  print_grid(grid_two);
  check_lose();
}
