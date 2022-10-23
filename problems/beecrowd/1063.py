def main():
    while True:
        n = int(input())
        if n == 0:
            break
        wagons = input().split()
        desired_order = input().split()
        station = []
        i = j = 0
        ans = ''
        while j < n:
            if i < n and desired_order[j] == wagons[i]:  # directly from wagons
                i, j, ans = i + 1, j + 1, ans + 'IR'
            elif station and desired_order[j] == station[-1]:  # from station
                station.pop()
                j, ans = j + 1, ans + 'R'
            else:  # try adding to the station if there is any wagon left
                if i == n:  # last wagon already added to station
                    ans += ' Impossible'
                    break
                else:
                    station.append(wagons[i])
                    i, ans = i + 1, ans + 'I'
        print(ans)
main()
