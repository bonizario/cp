def main():
    fatorials = [40320, 5040, 720, 120, 24, 6, 2, 1]
    n = int(input())
    ans = 0
    while n:
        for fatorial in fatorials:
            if fatorial <= n:
                n -= fatorial
                ans += 1
                break
    print(ans)
main()
