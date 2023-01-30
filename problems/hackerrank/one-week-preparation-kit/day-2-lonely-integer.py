#!/bin/python3

import math
import os
import random
import re
import sys

def lonelyinteger(a):
    '''
    from collections import defaultdict
    d = defaultdict(int)
    for num in a:
        d[num] += 1
    for num in d:
        if d[num] == 1:
            return num
    '''
    unique = a[0]
    for i in range(1, len(a)):
        unique ^= a[i]
    return unique

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = lonelyinteger(a)

    fptr.write(str(result) + '\n')

    fptr.close()
