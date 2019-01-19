#include "networking.h"
#include "boardgen.h"

char coor[2];
char buffer[BUFFER_SIZE];
int client_socket;
int mid_game = 1;

static void sighandler(int signo){
  if(signo == SIGINT){
    if(mid_game == 1){
      printf("\nSurrendering the game :(\n");
      strcpy(buffer, "Opponent surrenders the game: you win!");
      write(client_socket, buffer, sizeof(buffer));
      close(client_socket);
      exit(0);
    }
    else{
      strcpy(buffer, "Opponent has left!");
      write(client_socket, buffer, sizeof(buffer));
      close(client_socket);
      exit(0);
    }
  }
}

int main() {
  
  signal(SIGINT, sighandler);

  int listen_socket;
  int f;
  listen_socket = server_setup();

  while (1) {
    client_socket = server_connect(listen_socket);
    //WELCOME
    printf("[server %d] received: [%s]\n", getpid(), buffer);
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
    printf("\e[1;1H\e[2J");
    print_grids();
    strcpy(buffer, "Opponent's Ships are Ready");
    write(client_socket, buffer, sizeof(buffer));
    read(client_socket, buffer, sizeof(buffer));
    printf("received: [%s]\n", buffer);
  
    while(!check_lose() ||
	  strcmp(buffer, "You Won!") == 0 ||
	  recv(client_socket, buffer, sizeof(buffer), 0) != 0){
      //get coordinates
      printf("\nOpponent's Turn\n");
      read(client_socket, buffer, sizeof(buffer));
      if(strcmp(buffer, "Opponent surrenders the game: you win!") == 0){
	printf("%s\n", buffer);
	break;
      }
      strcpy(buffer, under_attack(buffer));
      printf("\e[1;1H\e[2J");
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
      printf("\e[1;1H\e[2J");
      print_grids();

    }//end read loop
    mid_game = 0;
    if(check_lose()){
      printf("You Lost :(\n");
      strcpy(buffer, "You Won!\n");
      write(client_socket, buffer, sizeof(buffer));
    }
    else if(strcmp(buffer, "Opponent has left!") == 0){
      printf("%s", buffer);
    }
    else{
      printf("You Won!\n");
    }
    printf("Play Again? (Y/N): \t");
    fgets(buffer, sizeof(buffer), stdin);
    if(strcmp(buffer, "N") == 0){
      close(client_socket);
      exit(0);
    }
    printf("Waiting for opponent...");
  }
}
