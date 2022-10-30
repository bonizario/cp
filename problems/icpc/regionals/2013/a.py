def main():
    while True:
        try:
            a, b, c = map(int, input().split())
        except EOFError:
            break
        if (a == 0 and b == 1 and c == 1) or (a == 1 and b == 0 and c == 0):
            print('A')
        elif (b == 0 and a == 1 and c == 1) or (b == 1 and a == 0 and c == 0):
            print('B')
        elif (c == 0 and a == 1 and b == 1) or (c == 1 and a == 0 and b == 0):
            print('C')
        else:
            print('*')
main()
