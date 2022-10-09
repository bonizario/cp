def main():
    while True:
        n = int(input())
        if n == 0:
            break
        sticks = [map(int, input().split()) for _ in range(n)]
        ans = pairs = 0
        for _, quantity in sticks:
            if quantity >= 2:
                pairs += quantity // 2
        print(pairs // 2)
    print()
main()
