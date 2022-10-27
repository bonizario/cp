def main():
    while True:
        try:
            n, l, c = map(int, input().split())
        except EOFError:
            break
        pages, current_l, current_c = 1, 1, 0
        for length in map(len, input().split()):
            if current_c == 0:
                current_c = length
            elif current_c + (length + 1) <= c:
                current_c += (length + 1)
            else:
                if current_l < l:
                    current_l += 1
                else:
                    current_l = 1
                    pages += 1
                current_c = length
            # print(f'word={word} pages={pages} current_c={current_c} current_l={current_l}')
        print(pages)
main()
