def main():
    while True:
        d, n = input().split()
        if d == n == '0':
            break
        n = n.replace(d, '')
        print(int(n) if n else '0')
main()
