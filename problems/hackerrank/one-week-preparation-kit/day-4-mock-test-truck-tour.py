#!/bin/python3

import math
import os
import random
import re
import sys

def truckTour(petrolpumps):
    # There is a guaranteed solution, although the description does not mention it
    index = gas = 0
    for i in range(len(petrolpumps)):
        gas += petrolpumps[i][0] - petrolpumps[i][1]
        if gas < 0:
            gas, index = 0, i + 1
    return index

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    petrolpumps = []

    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)

    fptr.write(str(result) + '\n')

    fptr.close()
