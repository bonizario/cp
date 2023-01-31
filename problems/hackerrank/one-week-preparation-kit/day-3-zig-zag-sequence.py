#!/bin/python3

# In this challenge, the task is to debug the existing code
# to successfully execute all provided test files.
# Note: You can modify at most three lines in the given code.
# You cannot add or remove lines of code.

def findZigZagSequence(a, n):
    a.sort()
    mid = int((n + 1)/2)
    a[mid-1], a[n-1] = a[n-1], a[mid-1]

    st = mid + 1
    ed = n - 1
    while(st <= ed):
        a[st], a[ed] = a[ed], a[st]
        st = st + 1
        ed = ed - 1

    for i in range (n):
        if i == n-1:
            print(a[i])
        else:
            print(a[i], end = ' ')
    return

test_cases = int(input())
for cs in range (test_cases):
    n = int(input())
    a = list(map(int, input().split()))
    findZigZagSequence(a, n)
