#!/usr/bin/python3
"""
Module that calculates the perimeter of an island
"""


def island_perimeter(grid):
    """Return the perimeter of the island in grid."""
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                # Check cell below
                if i + 1 < rows and grid[i + 1][j] == 1:
                    perimeter -= 2

                # Check cell to the right
                if j + 1 < cols and grid[i][j + 1] == 1:
                    perimeter -= 2

    return perimeter
