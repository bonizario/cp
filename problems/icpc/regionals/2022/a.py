def main():
    n = int(input())
    sequence = input()
    print(sum(len(seq) for seq in sequence.split('b') if len(seq) >= 2))

main()
