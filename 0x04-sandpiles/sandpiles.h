#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

int isStable(int grid1[3][3]);
void myprint_grid(int grid[3][3]);
void add_sandpiles(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
