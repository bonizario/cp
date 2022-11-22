def main():
    j, r = map(int, input().split())
    points = list(map(int, input().split()))
    players = [0] * j
    i = 0
    for point in points:
        players[i] += point
        i = (i + 1 if i < j - 1 else 0)
    m = max(players)
    for i in range(j - 1, -1, -1):
        if players[i] == m:
            print(i + 1)
            break
main()
