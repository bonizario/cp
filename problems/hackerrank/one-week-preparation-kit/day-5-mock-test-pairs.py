#!/bin/python3

import math
import os
import random
import re
import sys

def pairs(k, arr):
    ans, n, s = 0, len(arr), set(arr)
    diff = [num - k for num in arr if num - k > 0]
    for num in diff:
        if num in s:
            ans += 1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    result = pairs(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
