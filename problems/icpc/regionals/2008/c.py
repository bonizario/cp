def main():
    from collections import defaultdict
    while True:
        m, n = map(int, input().split())
        if m == n == 0:
            break
        l = int(input())
        k = int(input())
        v = defaultdict(int)
        h = defaultdict(int)
        lengths = sorted(map(int, input().split()), reverse=True)
        for length in lengths:
            v[length] += 1
            h[length] += 1
        total_columns = 0
        total_rows = 0
        empty_columns = m*100 // l
        empty_rows = n*100 // l
        if m*100 % l == 0 and n*100 % l == 0: # both vertical and horizontal possible
            for length in lengths:
                if empty_columns:
                    if length == n:
                        empty_columns -= 1; v[length] -= 1; total_columns += 1
                    elif length < n:
                        if (length == n - length and v[length] >= 2) or\
                            (length != n - length and v[length] >= 1 and v[n - length] >= 1):
                            v[length] -= 1; v[n - length] -= 1; empty_columns -= 1; total_columns += 2
                if empty_rows:
                    if length == m:
                        empty_rows -= 1; h[length] -= 1; total_rows += 1
                    elif length < m:
                        if (length == m - length and h[length] >= 2) or\
                            (length != m - length and h[length] >= 1 and h[m - length] >= 1):
                            h[length] -= 1; h[m - length] -= 1; empty_rows -= 1; total_rows += 2
                if empty_columns == 0 or empty_rows == 0:
                    break
        elif m*100 % l == 0: # only vertical possible
            for length in lengths:
                if length == n:
                    empty_columns -= 1; v[length] -= 1; total_columns += 1
                elif length < n:
                    if (length == n - length and v[length] >= 2) or\
                        (length != n - length and v[length] >= 1 and v[n - length] >= 1):
                        v[length] -= 1; v[n - length] -= 1; empty_columns -= 1; total_columns += 2
                if empty_columns == 0:
                    break
        elif n*100 % l == 0: # only horizontal possible
            for length in lengths:
                if length == m:
                    empty_rows -= 1; h[length] -= 1; total_rows += 1
                elif length < m:
                    if (length == m - length and h[length] >= 2) or\
                        (length != m - length and h[length] >= 1 and h[m - length] >= 1):
                        h[length] -= 1; h[m - length] -= 1; empty_rows -= 1; total_rows += 2
                if empty_rows == 0:
                    break
        if empty_columns == empty_rows == 0:
            best = min(total_columns, total_rows)
        elif empty_columns == 0:
            best = total_columns
        elif empty_rows == 0:
            best = total_rows
        else:
            best = 0
        print(best if best else 'impossivel')
main()
