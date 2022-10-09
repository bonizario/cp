def main():
    while True:
        b, n = map(int, input().split())
        if b == n == 0:
            break
        savings = list(map(int, input().split()))
        for _ in range(n):
            d, c, v = map(int, input().split())
            d, c = d - 1, c - 1
            savings[d] -= v
            savings[c] += v
        print('N' if any(s < 0 for s in savings) else 'S')
main()
