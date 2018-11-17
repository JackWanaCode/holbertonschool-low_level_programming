#!/usr/bin/python3

"""Calculate perimeter of island
Args:
grid: matrix that contain island.
Returns: perimeter of island"""


def island_perimeter(grid):
    """return perimeter of island
    """
    count = 0
    for row in range(0, len(grid)):
        for col in range(0, len(grid[0])):
            if grid[row][col] == 1:
                if grid[row - 1][col] == 0:
                    count += 1
                if grid[row + 1][col] == 0:
                    count += 1
                if grid[row][col + 1] == 0:
                    count += 1
                if grid[row][col - 1] == 0:
                    count += 1
    return count
