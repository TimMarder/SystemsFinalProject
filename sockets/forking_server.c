#include "networking.h"
#include "boardgen.h"
#include "gameplay.h"

void process(char *s);
void subserver(int from_client);

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
    
  while (read(client_socket, buffer, sizeof(buffer))) {
    process(buffer);
    write(client_socket, buffer, sizeof(buffer));
    
  }//end read loop

  close(client_socket);
  exit(0);

}

void process(char * s) {

  while (*s) {

    if (*s >= 'a' && *s <= 'z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    else  if (*s >= 'A' && *s <= 'Z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    s++;

  }
  
}
