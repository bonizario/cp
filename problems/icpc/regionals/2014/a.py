def main():
    from math import ceil
    while True:
        try:
            x, y = map(int, input().split())
        except EOFError:
            break
        print(ceil(y/(y-x)))
main()
