#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
    int a, b;
    double distance;
} Edge;

const int MAX_NODES = 1000, MAX_EDGES = MAX_NODES * (MAX_NODES - 1) / 2;

int find(vector<int>& G, int a) {
    if (a == G[a]) {
        return a;
    }
    return G[a] = find(G, G[a]);
}

int unify(vector<int>& G, vector<int>& S, int a, int b) {
    a = find(G, a), b = find(G, b);
    if (a == b) {
        return 0;
    }
    if (S[a] < S[b]) {
        swap(a, b);
    }
    G[b] = a, S[a] += S[b];
    return 1;
}

double euclidean_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((double)(x2 - x1), 2) + pow((double)(y2 - y1), 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int c, n;
    vector<Edge> edges(MAX_EDGES);
    vector<int> G(MAX_NODES), S(MAX_NODES);
    vector<pair<int, int>> points(MAX_NODES);
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            G[i] = i, S[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            auto& [x1, y1] = points[i];
            for (int j = i + 1; j < n; j++) {
                auto& [x2, y2] = points[j];
                edges[total++] = {i, j, euclidean_distance(x1, y1, x2, y2)};
            }
        }
        sort(edges.begin(),
             edges.begin() + total,
             [](const Edge& a, const Edge& b) { return a.distance < b.distance; });
        double length = 0;
        for (int i = 0; i < total; i++) {
            auto& [a, b, distance] = edges[i];
            length += unify(G, S, a, b) * distance;
            if (S[a] == n) {
                break;
            }
        }
        cout << fixed << setprecision(2) << length / 100 << "\n";
    }
    return 0;
}
