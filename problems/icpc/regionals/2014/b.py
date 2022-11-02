def main():
    def count_swaps_required_to_sort(n):
        i, swaps = 2, 1  # First swap
        while i != 1:
            i = (i + i) if i <= n else (i - n + i - n - 1)
            swaps += 1
        return swaps

    while True:
        try:
            p = int(input())
        except EOFError:
            break
        print(count_swaps_required_to_sort(p // 2))
main()

'''
def swap(n, array):
    swapped = [0] * (2*n)
    for i in range(n):
        swapped[2*i] = array[i + n]
        swapped[2*i + 1] = array[i]
    return swapped

def swaps_required_to_sort(p):
    array, n = list(range(1, p + 1)), p // 2
    sorted_array = sorted(array)
    swaps, array = 1, swap(n, array)
    while array != sorted_array:
        swaps += 1
        array = swap(n, array)
    return swaps
'''
