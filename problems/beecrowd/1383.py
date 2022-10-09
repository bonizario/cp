def main():
    for t in range(int(input())):
        matrix = []
        is_sudoku = True
        for _ in range(9):
            matrix.append(list(map(int, input().split())))
        for i in range(9):
            ok_row = set()
            ok_column = set()
            for j in range(9):
                ok_row.add(matrix[i][j])
                ok_column.add(matrix[j][i])
            if len(ok_row) != 9 or len(ok_column) != 9:
                is_sudoku = False
                break
        if is_sudoku:
            for m in range(0, 7, 3):
                for n in range(0, 7, 3):
                    ok = set()
                    for i in range(m, m + 3):
                        for j in range(n, n + 3):
                            ok.add(matrix[j][i])
                    if len(ok) != 9:
                        is_sudoku = False
        print(f'Instancia {t + 1}')
        print('SIM\n' if is_sudoku else 'NAO\n')
main()
