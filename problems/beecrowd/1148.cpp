#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int POSITIVE_INFINITY = 1e9;
const int MAXN = 501;
vector<pii> adj[MAXN];
bool visited[MAXN];
bool direct_path[MAXN][MAXN];
int dist[MAXN];

void dijkstra(int n, int s) {
    for (int i = 1; i <= n; i++)
        dist[i] = POSITIVE_INFINITY, visited[i] = false;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(dist[s], s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &[w, v] : adj[u]) {
            if (direct_path[u][v] && direct_path[v][u]) {
                dist[v] = min(dist[u], dist[v]);
                pq.push(pii(dist[v], v));
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, e, x, y, h, k;
    while (true) {
        cin >> n >> e;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            for (int j = 1; j <= n; j++)
                direct_path[i][j] = false;
        }
        for (int i = 0; i < e; i++) {
            cin >> x >> y >> h;
            direct_path[x][y] = true;
            adj[x].push_back(make_pair(h, y));
        }
        cin >> k;
        while (k--) {
            cin >> x >> y;
            dijkstra(n, x);
            if (dist[y] < POSITIVE_INFINITY) {
                cout << dist[y] << "\n";
            } else {
                cout << "Nao e possivel entregar a carta\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
