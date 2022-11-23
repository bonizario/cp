def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        vowels = [letter for letter in s if letter in 'aeiou']
        print('S' if vowels == vowels[::-1] else 'N')
main()
