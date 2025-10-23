#include <stdlib.h>
#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - Function to print menger square
 * @level: level of menger square
 *
 */
void menger(int level)
{
	int size, row, col;
	int x, y, temp_row, temp_col, print_hash;

	if (level < 0)
		return;

	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			print_hash = 1;
			temp_row = row;
			temp_col = col;

			while (temp_row > 0 || temp_col > 0)
			{
				x = temp_row % 3;
				y = temp_col % 3;
				if (x == 1 && y == 1)
				{
					print_hash = 0;
					break;
				}
				temp_row /= 3;
				temp_col /= 3;
			}
			if (print_hash)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
