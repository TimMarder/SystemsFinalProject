#include "boardgen.h"

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

void populate_grid(char *grid[10][10]){
  for(int r = 0; r < 10; r ++){
    for(int c = 0; c < 10; c ++){
      grid[r][c] = "~ ";
    }
  }
}

void print_grids(){
  char val = 'A';
  printf("     0 1 2 3 4 5 6 7 8 9  \t     0 1 2 3 4 5 6 7 8 9  \n");
  printf("--------------------------\t--------------------------\n");
  for(int r = 0; r < 10; r ++){
    printf(" %c | ", val);
    for(int c = 0; c < 10; c ++){
      printf("%s", grid_one[r][c]);
    }
    printf("|\t %c | ", val);
    val ++;
    for(int c = 0; c < 10; c ++){
      printf("%s", grid_two[r][c]);
    }
    printf("|\n");
  }
  printf("--------------------------\t--------------------------\n");
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
  char **arr = calloc(256, 5);
  //printf("%s\n", buffer);
  for(int i = 0; i < 5; i++){
    arr[i] = strsep(&buffer, "\n");
    //printf("%s\t", arr[i]);
  }
  //printf("\n");
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

int under_attack(char *coor){
  int a = get_alpha_coor(coor);
  int n = get_num_coor(coor);
  if(grid_two[a][n] == "@ "){
    grid_two[a][n] = "X ";
    return 1;
  }
  else{
    grid_two[a][n] = "O ";
    return 0;
  }
}

void check_hit(char *attack, int i){
  int a = get_alpha_coor(attack);
  int n = get_num_coor(attack);
  if(i)
    grid_one[a][n] = "X ";
  else
    grid_one[a][n] = "O ";
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
