def main():
    n = int(input())
    nums = [int(input()) for _ in range(n)]
    print(sum(num != 1 for num in nums))
main()
