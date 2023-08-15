def main():
    bits = input().split()
    print('S' if all(bit in '01' for bit in bits) else 'F')

main()
