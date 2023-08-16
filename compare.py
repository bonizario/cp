def main():
    from sys import argv

    if len(argv) == 1:
        print('Pass the file name as a command line argument')
        return

    try:
        output_file = open(f'{argv[1]}.out', 'r')
    except FileNotFoundError:
        print(f'File \'{argv[1]}.out\' not found')
        return
    try:
        myoutput_file = open(f'{argv[1]}.myout', 'r')
    except FileNotFoundError:
        print(f'File \'{argv[1]}.myout\' not found')
        return

    ok = True
    output_lines = output_file.readlines()
    myoutput_lines = myoutput_file.readlines()
    for line, out_line, myout_line in zip(range(len(output_lines)), output_lines, myoutput_lines):
        if out_line != myout_line:
            print(f'line {line} expected/got\n{out_line}{myout_line}')
            ok = False
    print('OK' if ok else '')
    output_file.close()
    myoutput_file.close()

main()
