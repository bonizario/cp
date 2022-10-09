#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int POSITIVE_INFINITY = 1e9;
const int MAXN = 501;

void dijkstra(int s, int n, vector<pii> adj[MAXN],
              int ok[MAXN][MAXN], int dist[MAXN], bool visited[MAXN]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = POSITIVE_INFINITY, visited[i] = false;
    }
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[w, v] : adj[u]) {
            if (ok[u][v] && ok[v][u]) {
                dist[v] = min(dist[u], dist[v]);
                pq.push(pii(dist[v], v));
            } else if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dist[MAXN];
    bool visited[MAXN];
    int ok[MAXN][MAXN];
    int n, e, k, x, y, h;
    vector<pii> adj[MAXN];
    while (true) {
        cin >> n >> e;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            for (int j = 1; j <= n; j++)
                ok[i][j] = false;
        }
        for (int i = 0; i < e; i++) {
            cin >> x >> y >> h;
            adj[x].push_back(pii(h, y));
            ok[x][y] = true;
        }
        cin >> k;
        while (k--) {
            cin >> x >> y;
            dijkstra(x, n, adj, ok, dist, visited);
            if (dist[y] != POSITIVE_INFINITY) {
                cout << dist[y] << "\n";
            } else {
                cout << "Nao e possivel entregar a carta\n";
            }
        }
        cout << "\n";
    }
}
