def main():
    from sys import argv
    if len(argv) == 1:
        print('Pass the file name as a command line argument')
        return
    try:
        out = open(f'{argv[1]}.out', 'r')
    except FileNotFoundError:
        print(f'File \'{argv[1]}.out\' not found')
        return
    try:
        myout = open(f'{argv[1]}.myout', 'r')
    except FileNotFoundError:
        print(f'File \'{argv[1]}.myout\' not found')
        return
    out_lines = out.readlines()
    myout_lines = myout.readlines()
    for line, out_line, myout_line in zip(range(len(out_lines)), out_lines, myout_lines):
        if out_line != myout_line:
            print(f'line {line + 1} expected/got\n{out_line}{myout_line}')
    out.close()
    myout.close()
main()
