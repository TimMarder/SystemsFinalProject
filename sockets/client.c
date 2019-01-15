#include "networking.h"

char *get_ip(){

  int fd = open("ip.txt", O_RDONLY);
  printf("opening: %s\n", strerror(errno));  

  char *buff = calloc(16, sizeof(char));
  printf("mallocing: %s\n", strerror(errno));

  int result = read(fd, buff, 16*sizeof(char));
  printf("Error %d: %s\n", result, strerror(result));
  
  printf("buffer: %s\n", buff);
  if(strstr(buff, "\n"))
    buff[strlen(buff) -1] = '\0';
  //char *address = buff;
  //free(buff);
  //return address;
  return buff;
}

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];

  //if (argc == 2)
  //if (*get_ip() != '\0')
  //server_socket = client_setup( get_ip() );
  if(argc == 2)
    server_socket = client_setup( argv[1] );
  else
    server_socket = client_setup( TEST_IP );

  while (1) {
    printf("enter data: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    write(server_socket, buffer, sizeof(buffer));
    read(server_socket, buffer, sizeof(buffer));
    printf("received: [%s]\n", buffer);
  }
}
