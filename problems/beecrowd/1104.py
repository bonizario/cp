def main():
    while True:
        a, b = map(int, input().split())
        if a == b == 0:
            break
        alice_set = set(input().split())
        beatriz_set = set(input().split())
        print(min(len(alice_set - beatriz_set), len(beatriz_set - alice_set)))
main()
