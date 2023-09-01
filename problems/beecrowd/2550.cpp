#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int a, b, c;
} Edge;

const int MAX_NODES = 1000, MAX_EDGES = MAX_NODES * (MAX_NODES - 1) / 2;

int find(vector<int>& G, int a) {
    if (a == G[a]) {
        return a;
    }
    return G[a] = find(G, G[a]);
}

bool unify(vector<int>& G, vector<int>& S, int a, int b) {
    a = find(G, a), b = find(G, b);
    if (a == b) {
        return false;
    }
    if (S[a] < S[b]) {
        swap(a, b);
    }
    G[b] = a, S[a] += S[b];
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int m, n;
    vector<Edge> edges(MAX_EDGES);
    vector<int> G(MAX_NODES), S(MAX_NODES);
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            G[i] = i, S[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> edges[i].a >> edges[i].b >> edges[i].c;
            edges[i].a -= 1, edges[i].b -= 1;
        }
        sort(edges.begin(),
             edges.begin() + m,
             [](const Edge& x, const Edge& y) { return x.c < y.c; });
        int cost = 0, components = n;
        for (int i = 0; i < m; i++) {
            auto& [a, b, c] = edges[i];
            if (unify(G, S, a, b)) {
                // mst[total++] = edges[i];
                components -= 1, cost += c;
                if (components == 1) {
                    break;
                }
            }
        }
        cout << (components == 1 ? to_string(cost) : "impossivel") << "\n";
    }
    return 0;
}
