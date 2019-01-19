#include "networking.h"
#include "boardgen.h"

void process(char *s);
void subserver(int from_client);
char coor[2];

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup();

  while (1) {

    int client_socket = server_connect(listen_socket);
    f = fork();
    if (f == 0)
      subserver(client_socket);
    else
      close(client_socket);
  }
}

void subserver(int client_socket) {

  char buffer[BUFFER_SIZE];

  //WELCOME
  printf("[subserver %d] received: [%s]\n", getpid(), buffer);
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
  write(client_socket, buffer, sizeof(buffer));
  read(client_socket, buffer, sizeof(buffer));
  printf("received: [%s]\n", buffer);
  
  while(!check_lose() || strcmp(buffer, "You Won!") == 0){
    //get coordinates
    printf("\nOpponent's Turn\n");
    read(client_socket, buffer, sizeof(buffer));
    strcpy(buffer, under_attack(buffer));
    print_grids();
    write(client_socket, buffer, sizeof(buffer));

    //enter coordinates
    printf("enter coordinates: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    strncpy(coor, buffer, 2);
    //send coordinates
    write(client_socket, buffer, sizeof(buffer));
    //hit?
    read(client_socket, buffer, sizeof(buffer));    
    printf("received: [%s]\n", buffer);
    check_hit(coor, buffer[0]);
    print_grids();

  }//end read loop

  if(check_lose()){
    printf("You Lost :(");
    strcpy(buffer, "You Won!");
    write(client_socket, buffer, sizeof(buffer));
  }
  else{
    printf("You Won!");
  }
  
  close(client_socket);
  exit(0);

}
