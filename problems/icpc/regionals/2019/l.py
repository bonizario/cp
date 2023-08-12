def main():
    def count_bits(n):
        bits = 0
        while n:
            bits += (n & 1)
            n >>= 1
        return bits

    # def pattern():
    #     from pprint import pprint
    #     for n in range(2, 20):
    #         nums = {i: [] for i in range(n + 1)}
    #         for i in range(2 ** n):
    #             bits = count_bits(i)
    #             nums[bits].append(bin(i)[2:].zfill(n))
    #         if n == 5: pprint(nums)
    #         print(f'n={n} bits={count_bits(n)} odds={sum((len(v) & 1) for v in nums.values())}')

    n = int(input())
    bits = count_bits(n)
    print(1 << bits) # same as 2 ** bits
    # pattern()

main()

'''
group 5 bits
11111 cannot use because len(group) is odd

group 4 bits
11110
11101
11011 cannot use because len(group) is odd
10111
01111

group 3 bits
11100
11001
10011
00111

group 2 bits
11000
10001 cannot use because len(group) is odd
00011

group 1 bit
10000
00001

group 0 bits
00000 cannot use because len(group) is odd
'''
