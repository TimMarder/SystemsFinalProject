#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


char *grid_one[13][13];
char *grid_two[13][13];

void create_grid(char *grid[13][13]){
  char s[10];
  char coorval = 'A';
  for(int row = 0; row< 13; row++){
    for(int col = 0; col< 13; col++){
      if(row == 0){
	if(col < 2)
	  grid[row][col] = "  ";
	else
	  sprintf(s, "%d", col-3);
	  grid[row][col] = s;
      }      
      else if(row == 1 || row == 12){
	grid[row][col] = "--";
      }
      else{
	if(col == 0){
	  grid[row][col] = ;
	  coorval++;
	}
	else if(col == 1 || col == 12)
	  grid[row][col] = "|\n";
	else
	  grid[row][col] = "~ ";
      }
    }
  }
}

int gen() {

    printf("\n");
    /*
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    printf("  -----------------------\n");
    printf("A | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("B | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("C | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("D | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("E | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("F | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("G | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("H | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("I | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("J | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ |\n");
    printf("  -----------------------\n");
    */
}

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

int * command_handle(){
  //Ex: A4
  char * steve = calloc(100,sizeof(char));
  fgets(steve, 100, stdin);
  int horizontal = steve[0] - 40 + 2; //Numerical value = Unicode Char - 40 shifted 2   
  int vertical = steve[1] + 2; //Second value shifted 2
  int coors[2] = {horizontal,vertical};
  return coors;
}

  
int main(){
  //int coors[5][2];
  give_coors("alphaCoords.txt");

  create_grid(grid_one);
  create_grid(grid_two);
  for(int r = 0; r < 13; r++){
    for(int c = 0; c < 13; c++){
      printf("%s", grid_one[r][c]);
    }
  }
  for(int r = 0; r < 13; r++){
    for(int c = 0; c < 13; c++){
      printf("%s", grid_two[r][c]);
    }
  }

}
