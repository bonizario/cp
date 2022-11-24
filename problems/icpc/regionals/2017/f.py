def main():
    n = int(input())
    k = int(input())
    scores = sorted([int(input()) for _ in range(n)], reverse=True)
    ans = k
    for i in range(k, n):
        if scores[i] != scores[k - 1]:
            break
        ans += 1
    print(ans)
main()
