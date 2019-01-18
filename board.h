#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char *grid_one[10][10];
char *grid_two[10][10];

void populate_grid(char *grid[10][10]);
void print_grid();

int check_coor(char *coor);
int get_alpha_coor(char *coor);
int get_num_coor(char *coor);

char **get_ship_placement();
void place_ships();

int under_attack(char *coor);
//void check_hit(char *attack);
int check_lose();
