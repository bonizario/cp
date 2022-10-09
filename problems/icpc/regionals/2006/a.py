def main():
    while True:
        p, n, c = map(int, input().split())
        if p == n == c == 0:
            break
        matrix = [list(map(int, input().split())) for _ in range(n)]
        ans = 0
        for j in range(p):
            curr = 0
            for i in range(n):
                if matrix[i][j] == 1:
                    curr += 1
                    if curr >= c and i == n - 1 :
                        ans += 1
                else:
                    if curr >= c:
                        ans += 1
                    curr = 0
                # print(f'ans = {ans}')
        print(ans)
main()
