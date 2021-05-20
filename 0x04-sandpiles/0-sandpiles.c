#include "sandpiles.h"

/**
 * myprint_grid - print grid
 * @grid1: grid to print
 */
void myprint_grid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

/**
 * isStable - Check if the grid is stable,
 * stable means that each cell is less than 4
 * @grid1: 3x3 grid
 * Return: 1 if is stable, otherwise return 0
 *
 */
int isStable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (0);
	return (1);
}

/**
 * add_sandpiles - sum two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * topple - removes grains of sand of each cell
 * @grid1: grid
 */
void topple(int grid1[3][3])
{
	int x, y, row, col, i, j, num = 0, n = 0;
	int nextpiles[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			num = grid1[row][col];
			if (num < 4)
				nextpiles[row][col] = grid1[row][col];
		}
	}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			n = grid1[x][y];

			if (n >= 4)
			{
				nextpiles[x][y] += (n - 4);
				/* down */
				if ((x + 1) < 3)
					nextpiles[x + 1][y]++;
				/* up */
				if ((x - 1) >= 0)
					nextpiles[x - 1][y]++;
				/* Right */
				if ((y + 1) < 3)
					nextpiles[x][y + 1]++;
				/* left */
				if ((y - 1) >= 0)
					nextpiles[x][y - 1]++;
			}
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = nextpiles[i][j];
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: grid
 * @grid2: grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_sandpiles(grid1, grid2);
	while (!isStable(grid1))
	{
		printf("=\n");
		myprint_grid(grid1);
		topple(grid1);
	}
}
