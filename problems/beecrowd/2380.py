def main():
    from sys import stdin, stdout

    def find(G, a):
        if a == G[a]:
            return a
        G[a] = find(G, G[a])
        return G[a]

    def union(G, S, a, b):
        a, b = find(G, a), find(G, b)
        if S[a] > S[b]:
            G[b] = a
            S[a] += S[b]
        else:
            G[a] = b
            S[b] += S[a]

    n, k = map(int, stdin.readline().split())
    G, S = list(range(n)), [1] * n
    for _ in range(k):
        query, a, b = stdin.readline().split()
        a, b = int(a) - 1, int(b) - 1
        if query == 'F':
            union(G, S, a, b)
        else:
            stdout.write('S\n' if find(G, a) == find(G, b) else 'N\n')

main()
