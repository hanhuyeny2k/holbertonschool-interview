#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - print the grid
 * @grid: the matrix
 *
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * check_indices - check to see if the indices are greater than 4
 * @grid1: the matrix
 *
 * Return: 1 if indices are greater than 4 else return 0
 */
int check_indices(int grid1[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			if (grid1[x][y] >= 4)
				return (1);
	}
	return (0);
}

/**
 * sandpiles_sum - add the sum of two matrices together
 * @grid1: the matrix 1
 * @grid2: the matrix 2
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];

	}
	while (check_indices(grid1) == 1)
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}


/**
 * topple - topple the matrix once the index is greater than 3
 * @grid: the matrix
 *
 */
void topple(int grid[3][3])
{
	int x, y;
	int nextpiles[3][3] = {{0}};
	int num;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			num = grid[x][y];
			if (num < 4)
				nextpiles[x][y] += grid[x][y];
			if (num >= 4)
			{
				nextpiles[x][y] += num - 4;
				if (x < 2)
					nextpiles[x + 1][y]++;
				if (x >= 1)
					nextpiles[x - 1][y]++;
				if (y < 2)
					nextpiles[x][y + 1]++;
				if (y >= 1)
					nextpiles[x][y - 1]++;
			}
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid[x][y] = nextpiles[x][y];
		}
	}
}
