#!/bin/python3

import math
import os
import random
import re
import sys

def gridChallenge(grid):
    n, m = len(grid), len(grid[0])
    for i in range(n):
        grid[i] = ''.join(sorted(grid[i]))
    for i in range(m):
        for j in range(n - 1):
            if grid[j + 1][i] < grid[j][i]:
                return 'NO'
    return 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        grid = []

        for _ in range(n):
            grid_item = input()
            grid.append(grid_item)

        result = gridChallenge(grid)

        fptr.write(result + '\n')

    fptr.close()
