#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int x, y, z;
} Edge;

const int MAX_NODES = 200000, MAX_EDGES = 200000;

int find(vector<int>& G, int x) {
    if (x == G[x]) {
        return x;
    }
    return G[x] = find(G, G[x]);
}

int unify(vector<int>& G, vector<int>& S, int x, int y) {
    x = find(G, x), y = find(G, y);
    if (x == y) {
        return 0;
    }
    if (S[x] < S[y]) {
        swap(x, y);
    }
    G[y] = x, S[x] += S[y];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int m, n;
    vector<Edge> edges(MAX_EDGES);
    vector<int> G(MAX_NODES), S(MAX_NODES);
    while (cin >> m >> n && m + n) {
        int original_cost = 0, optimized_cost = 0;
        for (int i = 0; i < m; i++) {
            G[i] = i, S[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> edges[i].x >> edges[i].y >> edges[i].z;
            original_cost += edges[i].z;
        }
        sort(edges.begin(),
             edges.begin() + n,
             [](const Edge& a, const Edge& b) { return a.z < b.z; });
        for (int i = 0; i < n; i++) {
            auto& [x, y, z] = edges[i];
            optimized_cost += unify(G, S, x, y) * z;
            if (S[x] == m) {
                break;
            }
        }
        cout << original_cost - optimized_cost << "\n";
    }
    return 0;
}
