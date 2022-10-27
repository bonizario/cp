def main():
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        notes = tuple(map(int, input().split()))
        total = sum(notes)
        if total % n != 0:
            print('-1')
            continue
        final_note = total // n
        print(1 + sum(note - final_note for note in notes if (note - final_note > 0)))
main()
