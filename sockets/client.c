#include "networking.h"
#include "boardgen.h"

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];
  char coor[2];
  
  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  //WELCOME
  printf("Welcome to Battleships!\n");
  populate_grid(grid_one);
  populate_grid(grid_two);
  print_grids();

  //SETUP
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
  
  while(!check_lose() || strcmp(buffer, "You Won!") == 0){
    printf("Your Turn!\n");
    printf("enter coordinate: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    strncpy(coor, buffer, 2);
    //send coordinates
    write(server_socket, buffer, sizeof(buffer));
    //hit?
    read(server_socket, buffer, sizeof(buffer));    
    printf("received: [%s]\n", buffer);
    check_hit(coor, buffer[0]);
    print_grids();

    printf("\nOpponent's Turn\n");
    read(server_socket, buffer, sizeof(buffer));
    strcpy(buffer, under_attack(buffer));
    print_grids();
    write(server_socket, buffer, sizeof(buffer));
  }
  
  if(check_lose()){
    printf("You Lost :(");
    strcpy(buffer, "You Won!");
    write(server_socket, buffer, sizeof(buffer));
  }
  else{
    printf("You Won!");
  }
  
}
