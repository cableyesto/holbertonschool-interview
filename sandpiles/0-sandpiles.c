#include <stdlib.h>
#include "sandpiles.h"
#include <stdio.h>

/**
 * is_sandpile_stable - Function to check if a sandpile is stable.
 * @grid: square matrix 3x3.
 *
 * Return: 0 if grid is not stable, 1 if it is stable.
 */
int is_sandpile_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpile_toppling - Perform one toppling round on a 3x3 grid.
 * @grid: 3x3 grid.
 */
void sandpile_toppling(int grid[3][3])
{
	int i, j, d;
	int temp[3][3] = {{0}};
	int directions[4][2] = {
		{1, 0},   /* down */
		{-1, 0},  /* up */
		{0, 1},   /* right */
		{0, -1}   /* left */
	};

	for (i = 0; i < 3; i++) /* Copy the current grid to temp */
	{
		for (j = 0; j < 3; j++)
			temp[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; i++) /* Topple unstable cells */
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;

				for (d = 0; d < 4; d++)
				{
					int ni = i + directions[d][0];
					int nj = j + directions[d][1];

					if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
						temp[ni][nj] += 1;
				}
			}
		}
	}

	for (i = 0; i < 3; i++) /* Copy temp back into original grid */
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = temp[i][j];
	}
}

/**
 * print_grid - Print 3x3 grid.
 * @grid: 3x3 grid.
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
 * sandpiles_sum - Function to sum two square matrices and perform toppling.
 * @grid1: first 3x3 matrix.
 * @grid2: second 3x3 matrix.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	/* Print the result of the sum if unstable */
	if (!is_sandpile_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
	}

	/* Keep toppling until the grid is stable */
	while (!is_sandpile_stable(grid1))
	{
		sandpile_toppling(grid1);

		/* Print grid after each toppling if still unstable */
		if (!is_sandpile_stable(grid1))
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}
