#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
*/

int carrier_coors[3];
int bship_coors[3];
int cruiser_coors[3];
int sub_coors[3];
int destroyer_coors[3];

char *grid_one[10][10];
char *grid_two[10][10];

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

int ship_coors[17][2]; //2D Array: 5+4+3+3+2 = 17; 17/100 squares have a ship on them.  Ex: {{0,0},{0,1},{0,2},{0,3}} 

//Returns -1 if coordinates hit area already targeted OR if those are invalid coordinates.
//Returns 0 if coordinates hit water.
//Returns 1 if coordinates hit a ship.
int hit_detection(char * coors){
  if (strlen(coors) != 2){
    printf("Invalid command: Command isn't even the right size.  \n Valid commands include things like: A0, B6, F9, C4");
    return -1;
  }

  int letter = get_alpha_coor(coors);
  int number = get_num_coor(coors);
  for (int i = 0; i < 17; i++){
    int valid_alpha = get_alpha_coor(ship_coors[i][0]);
    int valid_num = get_num_coor(ship_coors[i][1]);
    if ((letter == valid_alpha) && (number == valid_num)){
      printf("That's a hit!");
      modify_grid('X',coors);
      return 1;
    }
  }
  printf("Splash!  You get NOTHING!  Good day to you, sir!");
  modify_grid('O',coors);
  return 0;
}
  


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
/*
int check_ship_placement(char *coor, int ship_len){
  char *end_coor[2];
  if(coor[2] != '0' || coor[2] != '1')
    return 0;
  else if(coor[2] == 0){
    end_coor[1] = coor[1] -'A' + ship_len;
  }
  else if(coor[2] == 1){
    end_coor[0] = coor[0] -'0' + ship_len;
  }
  if(strlen(coor) != 3)
    return 0;
  else if(!check_coor(coor))
    return 0;
  else if(!check_coor(end_coor))
    return 0;
  else
    return 1;
    }*/

int give_coors(char * filename){
  int coordfile;
  char *coordinates = (char *)malloc(360);
  //coordfile  = open(filename, O_RDONLY);
  read(coordfile, coordinates, 360);
  close(coordfile);

  printf("%s",coordinates);
  
  
  
}
struct ship{
  int size;
  int health;
  int starting_coors;
  int orient;
};
  
struct ship modify(int _size, int _health, int _starting_coors, int _orient){
  struct ship s;
  s.size = _size;
  s.health = _health;
  s.starting_coors = _starting_coors;
  s.orient = _orient;
  return s;
}




/*
struct Ship carrier(){
    
struct Ship battleship;
struct Ship cruiser;
struct Ship submarine;
struct Ship destroyer;
*/
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
}
