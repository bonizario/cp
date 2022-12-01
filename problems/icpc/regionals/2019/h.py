def main():
    from math import ceil
    v, n = map(int, input().split())
    print(' '.join(str(ceil(x*v*n/10)) for x in range(1, 10)))
main()
