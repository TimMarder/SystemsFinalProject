#include "networking.h"

void process(char *s);
void subserver(int from_client);

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup(get_ip());
  
  while (1) {

    int client_socket = server_connect(listen_socket);
    char buffer[BUFFER_SIZE];
    
    while (read(client_socket, buffer, sizeof(buffer))) {
      
      printf("[server %d] received: [%s]\n", getpid(), buffer);
      process(buffer);
      write(client_socket, buffer, sizeof(buffer));
    }//end read loop
    close(client_socket);
  }
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
