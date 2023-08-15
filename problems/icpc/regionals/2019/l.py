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
