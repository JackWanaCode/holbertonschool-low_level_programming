#!/usr/bin/python3


def island_perimeter(grid):
    """return perimeter of island
    """
    count = 0
    for row in range(1, len(grid) - 1):
        for col in range(1, len(grid[0]) - 1):
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
