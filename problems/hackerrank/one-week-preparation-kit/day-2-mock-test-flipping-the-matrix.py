#!/bin/python3

import math
import os
import random
import re
import sys

def flippingMatrix(matrix):
    n, k, max_sum = len(matrix) // 2, len(matrix) - 1, 0
    for i in range(n):
        for j in range(n):
            max_sum += max(matrix[i][j],
                           matrix[i][k-j],
                           matrix[k-i][j],
                           matrix[k-i][k-j])
    return max_sum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        matrix = []

        for _ in range(2 * n):
            matrix.append(list(map(int, input().rstrip().split())))

        result = flippingMatrix(matrix)

        fptr.write(str(result) + '\n')

    fptr.close()
