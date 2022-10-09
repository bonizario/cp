def main():
    while True:
        k = int(input())
        if k == 0:
            break
        n, m = map(int, input().split())
        houses = [map(int, input().split()) for _ in range(k)]
        for x, y in houses:
            if x == n or y == m:
                print('divisa')
            elif x > n and y > m:
                print('NE')
            elif x < n and y > m:
                print('NO')
            elif x < n and y < m:
                print('SO')
            else:
                print('SE')
main()
