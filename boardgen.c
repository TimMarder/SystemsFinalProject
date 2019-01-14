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

//int coors[5][2];
int main() {

  give_coors("alphaCoords.txt");
  
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
  coordfile  = open(filename, O_RDONLY);
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

