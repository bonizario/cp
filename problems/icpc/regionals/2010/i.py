def main():
    def dfs(v, adj, visited):
        visited[v] = True
        for u in adj[v]:
            if not visited[u]:
                dfs(u, adj, visited)

    # def transpose(n, adj):
    #     transpose_adj = [[] for _ in range(n)]
    #     for i in range(n):
    #         for v in adj[i]:
    #             transpose_adj[v].append(i)
    #     return transpose_adj

    def is_strongly_connected(n, adj, transpose_adj, visited):
        dfs(0, adj, visited)
        if not all(visited):
            return False
        visited = [False] * n
        dfs(0, transpose_adj, visited)
        if not all(visited):
            return False
        return True

    while True:
        n, m = map(int, input().split())
        if n == m == 0:
            break
        visited = [False] * n
        adj = [[] for _ in range(n)]
        transpose_adj = [[] for _ in range(n)]
        for _ in range(m):
            v, w, p = map(int, input().split())
            v, w = v - 1, w - 1
            adj[v].append(w)
            transpose_adj[w].append(v)
            if p == 2:
                adj[w].append(v)
                transpose_adj[v].append(w)
        print(1 if is_strongly_connected(n, adj, transpose_adj, visited) else 0)

main()
