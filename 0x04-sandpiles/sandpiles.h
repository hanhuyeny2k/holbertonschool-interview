#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

void topple(int grid[3][3]);
static void print_grid(int grid[3][3]);


#endif /* SANDPILES_H */
