#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

bool visited[MAXN];
int n, m, k, a, b, G[MAXN];
vector<int> adj[MAXN];

void removeRelationships(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto v : adj[s]) {
        G[v]--;
        if (G[v] < k) removeRelationships(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    while (cin >> n >> m >> k) {
        for (int i = 1; i <= n; i++) {
            G[i] = 0, visited[i] = false, adj[i].clear();
        }
        while (m--) {
            cin >> a >> b;
            G[a]++, G[b]++;
            adj[a].push_back(b), adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (G[i] < k && !visited[i]) {
                removeRelationships(i);
            }
        }
        bool hasPrinted = false;
        for (int i = 1; i <= n; i++) {
            if (G[i] >= k) {
                cout << (hasPrinted ? " " : "") << i;
                hasPrinted = true;
            }
        }
        cout << (hasPrinted ? "\n" : "0\n");
    }
    return 0;
}
