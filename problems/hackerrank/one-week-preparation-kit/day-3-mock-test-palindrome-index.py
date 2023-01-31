#!/bin/python3

import math
import os
import random
import re
import sys

def palindromeIndex(s):
    if s == s[::-1]:
        return -1
    n = len(s)
    i, j = 0, n - 1
    ans, diff = -1, 0
    while i < j:
        if s[i] != s[j]:
            if diff == 0:
                diff += 1
                front_is_equal = s[i + 1] == s[j]
                back_is_equal = s[i] == s[j - 1]
                if front_is_equal and back_is_equal:
                    if s[i + 2] == s[j - 1]:
                        ans = i
                        i += 1
                    else:
                        ans = j
                        j -= 1
                elif front_is_equal:
                    ans = i
                    i += 1
                elif back_is_equal:
                    ans = j
                    j -= 1
            else:
                return -1
        i += 1
        j -= 1
    return ans


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()
