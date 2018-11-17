#!/usr/bin/python3

"""Calculate perimeter of island
Args:
grid: matrix that contain island.
Returns: perimeter of island"""


def island_perimeter(grid):
    """return perimeter of island
    """
    count = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                if row == 0 or grid[row - 1][col] == 0:
                    count += 1
                if row == len(grid) - 1 or grid[row + 1][col] == 0:
                    count += 1
                if col == len(grid[row]) - 1 or grid[row][col + 1] == 0:
                    count += 1
                if col == 0 or grid[row][col - 1] == 0:
                    count += 1
    return count
