def main():
    # As C is a multiple of N, it is enough to look among the divisors of C
    # for the smallest number that satisfies all restrictions.
    # To do this you test only up to the root of N, so the solution has complexity O(sqrt(C)).

    def is_valid(a, b, c, d, n):
        return (n % a == 0) and (n % b != 0) and (c % n == 0) and (d % n != 0)

    a, b, c, d = map(int, input().split())

    i, ans = 1, c + 1
    while i * i <= c:
        if c % i == 0:                       # "c" is a multiple of "i", so "i" might be "n"
            if is_valid(a, b, c, d, i):      # "i" is a divisor of c
                ans = min(ans, i)
            if is_valid(a, b, c, d, c // i): # "c/i" is also a divisor of c
                ans = min(ans, c // i)
        i += 1

    print(ans if ans < c + 1 else -1)

main()
