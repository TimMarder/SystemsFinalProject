#include "boardgen.h"

void welcome(){
  printf("Welcome to Battleships!\n");
  populate_grid(grid_one);
  populate_grid(grid_two);
  print_grids();
}

void setup(){
  printf("Please input your ship coordinates in the file alphaCoords.txt provided\nFormat:RowColumnOrientationLength\nNew line for each ship\nExample:\nA4H5\n");
  printf("Ready? Hit Enter:\t");
  fgets(buffer, sizeof(buffer), stdin);
  get_ship_placement();
  place_ships();
  print_grids();
  strcpy(buffer, "Opponent's Ships are Ready");
  write(server_socket, buffer, sizeof(buffer));
  read(server_socket, buffer, sizeof(buffer));
  printf("received: [%s]\n", buffer);

}
