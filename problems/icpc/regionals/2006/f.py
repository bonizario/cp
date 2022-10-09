def main():
    while True:
        t, n = map(int, input().split())
        if t == n == 0:
            break
        teams = []
        for _ in range(t):
            _, points = input().split()
            teams.append(int(points))
        print(n*3-sum(teams))
main()
