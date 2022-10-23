'''
Time Complexity: O(NlogN)
Sort the reversed intervals in ascending order:
[(1, 3), (2, 5), (4, 6)] -> [(3, 1), (5, 2), (6, 4)]
Get the end of the first pair: (3, 1) -> 3
Pass through all intervals that have a starting point lower or equal to 3
1 photo can be used for both (3, 1) and (5, 2)
After reaching (6, 4), the inner while loop stops,
and the pointer goes to the next outer while iteration
2 photos will be required
'''
def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        intervals = sorted(tuple(map(int, reversed(input().split()))) for _ in range(n))
        ans = i = 0
        while i < n:
            ans += 1
            current_end = intervals[i][0]
            while i < n and intervals[i][1] <= current_end:
                i += 1
        print(ans)
main()
