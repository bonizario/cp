def main():
    from subprocess import run
    from sys import argv

    if len(argv) < 3 or not argv[1].isalpha() or not argv[2].isdigit():
        print('Pass the problem letter and input size as command line arguments')
        return

    problem_letter, input_size = argv[1].upper(), int(argv[2])
    for i in range(1, input_size + 1):
        try:
            run([f'python3 {problem_letter.lower()}.py < input/{problem_letter}_{i} > myoutput/{problem_letter}_{i}'], shell=True)
        except:
            print(f'Error while running test case {i}')
            return

        try:
            output_file = open(f'output/{problem_letter}_{i}')
        except FileNotFoundError:
            print(f'File \'output/{problem_letter}_{i}\' not found')
            return

        try:
            myoutput_file = open(f'myoutput/{problem_letter}_{i}')
        except FileNotFoundError:
            print(f'File \'myoutput/{problem_letter}_{i}\' not found')
            return

        ok = True
        output_lines = output_file.readlines()
        myoutput_lines = myoutput_file.readlines()
        for line, out_line, myout_line in zip(range(len(output_lines)), output_lines, myoutput_lines):
            if out_line != myout_line:
                print(f'test {i} line {line} expected/got\n{out_line}{myout_line}')
                ok = False
        print('OK' if ok else '')
        output_file.close()
        myoutput_file.close()

main()
