def main():
    while True:
        size_a, size_b = map(int, input().split())
        if size_a == size_b == 0:
            break
        a = set(map(int, input().split()))
        b = set(map(int, input().split()))
        print(min(len(a.difference(b)), len(b.difference(a))))
main()
