#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 250;
const int POSITIVE_INFINITY = 1e9;

int dist[MAXN];
int route[MAXN];
bool visited[MAXN];
vector<pii> adj[MAXN];

void dijkstra(int n, int c, int s) {
    for (int i = 0; i < n; i++)
        dist[i] = POSITIVE_INFINITY, visited[i] = false;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &[w, v] : adj[u]) {
            if (u >= c - 1 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(pii(dist[v], v));
            }
        }
        if (u < c - 1 && dist[c - 1] > dist[u] + route[c - 1] - route[u]) {
            dist[c - 1] = dist[u] + route[c - 1] - route[u];
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, c, k, u, v, p;
    ifstream cin("d.in");
    ofstream cout("d.myout");

    while (true) {
        cin >> n >> m >> c >> k;
        if (n == 0 && m == 0 && c == 0 && k == 0) break;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            adj[u].push_back(pii(p, v));
            adj[v].push_back(pii(p, u));
            if (abs(u - v) == 1)
                route[max(u, v)] = p;
        }
        for (int i = 1; i <= c - 1; i++) {
            route[i] += route[i - 1];
        }
        dijkstra(n, c, k);
        cout << dist[c - 1] << "\n";
    }
    return 0;
}
