while True:
    try:
        k, n = map(int, input().split())
    except EOFError:
        break
    nums = input().split()
    unique = set()
    ans = ''
    for num in nums:
        if num not in unique:
            unique.add(num)
            n -= 1
            if n > 0:
                ans += num + ' '
        if n == 0:
            ans += num
            break
    print(ans)
