/*
    https://www.dropbox.com/s/q4aa8g0zctzbwnq/solucoes_regional_2013.pdf
    Time Complexity: O(MlogM + SlogS)
    Referring to sorting the edges and executing Kruskal's Algorithm with modified Union-Find
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int a, b, p;
} Edge;

const int MAXN = 20001;
const int MAXM = 100001;
const int MAXS = 50000;

// Arrays required in Kruskal's Algorithms
Edge edges[MAXM];      // Edge mst[MAXM];  // No need to save MST edges
int G[MAXN], S[MAXN];  // Parents, Sizes
// Arrays required to manipulate the queries
int answers[MAXS];
vector<int> ids[MAXN];
pair<int, int> queries[MAXS];

int find(int a) {
    if (G[a] == a) return a;
    return G[a] = find(G[a]);
}

void unify(int a, int b, int p) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (S[a] < S[b]) swap(a, b);
    G[b] = a, S[a] += S[b];
    for (auto id : ids[b]) {      // For each query that "b" participates
        if (answers[id] == -1) {  // If query is not already answered
            if (find(queries[id].first) == find(queries[id].second)) {
                // If the other query participant is already part of the Connected Component (CC)
                // The current edge is the smallest of the CC that is involved in the connection of "a" and "b"
                // (Because the edges are sorted in descending order by weight)
                answers[id] = p;
            }
        }
        // Pushes the unanswered query into the root "a" (parent of "b")
        if (answers[id] == -1) ids[a].push_back(id);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, s, a, b;
    while (cin >> n >> m >> s) {
        for (int i = 1; i <= n; i++) {
            G[i] = i, S[i] = 1, ids[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            cin >> edges[i].a >> edges[i].b >> edges[i].p;
        }
        for (int i = 0; i < s; i++) {
            cin >> a >> b;
            answers[i] = -1, queries[i].first = a, queries[i].second = b;
            // Store which queries the nodes "a" and "b" are participating
            ids[a].push_back(i), ids[b].push_back(i);
        }
        sort(edges + 1,
             edges + m + 1,
             [](const Edge &x, const Edge &y) { return x.p > y.p; });
        for (int i = 1; i <= m; i++) {
            if (find(edges[i].a) != find(edges[i].b)) {
                unify(edges[i].a, edges[i].b, edges[i].p);
                // mst[++mst_size] = edges[i];  // No need to save MST edges
            }
        }
        for (int i = 0; i < s; i++) {
            cout << answers[i] << "\n";
        }
        // for (int i = 1; i < n; i++) {  // mst_size == n - 1 (e.g.: 4 nodes, mst has 3 edges)
        //     cout << "a=" << mst[i].a << " b=" << mst[i].b << " p=" << mst[i].p << "\n";
        // }
    }
    return 0;
}
