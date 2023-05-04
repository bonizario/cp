def main():
    for _ in range(int(input())):
        n, c, m = map(int, input().split())
        floors = sorted(map(int, input().split()), reverse=True)
        energy = 0
        for i in range(0, m, c):
            energy += (2 * floors[i])
        print(energy)
main()
