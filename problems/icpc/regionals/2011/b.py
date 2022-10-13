def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        boots = {i: {'E': 0, 'D': 0} for i in range(30, 61)}
        for _ in range(n):
            m, l = input().split()
            boots[int(m)][l] += 1
        ans = sum(min(pair['E'], pair['D']) for pair in boots.values())
        print(ans)
main()
