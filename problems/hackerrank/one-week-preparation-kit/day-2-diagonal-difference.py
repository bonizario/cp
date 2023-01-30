#!/bin/python3

import math
import os
import random
import re
import sys

def diagonalDifference(arr):
    k = n = len(arr)
    primary_diagonal = secondary_diagonal = 0
    for i in range(n):
        for j in range(n):
            if i == j:
                primary_diagonal += arr[i][j]
        k -= 1
        secondary_diagonal += arr[i][k]
    return abs(primary_diagonal - secondary_diagonal)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
