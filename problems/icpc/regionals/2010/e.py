def main():
    while True:
        l, c, r1, r2 = map(int, input().split())
        if l == c == r1 == r2 == 0:
            break
        # possible = False
        if r1 < r2:
            d1, d2 = 2 * r2, 2 * r1
        else:
            d1, d2 = 2 * r1, 2 * r2
        if (d1 + d2 <= l and d1 <= c) or \
        (d1 + d2 <= c and d1 <= l) or \
        (l >= d1 and c >= d1 and d1 + d2 <= (l**2+c**2)**0.5): # errado
            print('S')
        else:
            print('N')
main()
