def main():
    while True:
        h1, m1, h2, m2 = map(int, input().split())
        if h1 == m1 == h2 == m2 == 0:
            break
        if h2 > h1:
            if m2 > m1:
                print(m2-m1 + (h2-h1)*60)
            else:
                print(60-m1+m2 + (h2-h1-1)*60)
        elif h1 == h2:
            print(m2-m1 if m2 > m1 else 23*60+60-m1+m2)
        else:
            if m2 > m1:
                print(m2-m1 + (24-h1+h2)*60)
            else:
                print(60-m1+m2 + (23-h1+h2)*60)
main()
