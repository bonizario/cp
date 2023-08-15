def main():
    from math import ceil

    v, n = map(int, input().split())
    print(' '.join(str(ceil(v * n * i / 100)) for i in range(10, 100, 10)))
    # print(' '.join(str((v * n - 1) * i // 100 + 1) for i in range(10, 100, 10)))

main()
