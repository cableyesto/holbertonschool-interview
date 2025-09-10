#include <stdlib.h>
#include "sandpiles.h"
#include <stdio.h>

/**
* is_sandpile_stable - Function to sum to square matrixes
* @grid: square matrix 3x3
* Return: integer 0 if grid is not stable and 1 otherwise
*/
int is_sandpile_stable(int grid[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
	for (j = 0; j < 3; j++)
	{
		if (grid[i][j] > 3)
		{
			return (0);
		}
	}
    }
    return (1);
}



/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
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
 * sandpile_toppling - Toppling Function
 * @grid: 3x3 grid
 */
void sandpile_toppling(int grid[3][3])
{
    int directions[4][2] = {
	{1, 0},   /* down */
	{-1, 0},  /* up */
	{0, 1},   /* right */
	{0, -1}   /* left */
    };

    for (int i = 0; i < 3; i++)
    {
	for (int j = 0; j < 3; j++)
	{
		if (grid[i][j] > 3)
		{
			grid[i][j] -= 4;

			/* Add 1 to each valid neighbor */
			for (int d = 0; d < 4; d++)
			{
				int ni = i + directions[d][0];
				int nj = j + directions[d][1];

				if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
				{
					grid[ni][nj] += 1;
				}
			}
		}
	}
    }
}

/**
* sandpiles_sum - Function to sum to square matrixes
* @grid1: first square matrix 3x3
* @grid2: second square matrix 3x3
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    /* Print the result of the sum of the sandpiles */
    for (i = 0; i < 3; i++)
    {
	for (j = 0; j < 3; j++)
	{
		grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
    }

	if (is_sandpile_stable(grid1) != 1)
	{
	printf("=\n");
		print_grid(grid1);
	}

    while (is_sandpile_stable(grid1) != 1)
    {
	sandpile_toppling(grid1);
	if (is_sandpile_stable(grid1) != 1)
	{
		printf("=\n");
		print_grid(grid1);
	}
    }
}
