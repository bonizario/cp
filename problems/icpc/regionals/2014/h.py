def main():
    while True:
        try:
            n, m = map(int, input().split())
        except EOFError:
            break
        print(sum(all(map(int, input().split())) for _ in range(n)))
main()
