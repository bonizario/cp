#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, bool& has_cicle) {
    // already fully visited or cicle found
    if (visited[node] == 1 || has_cicle) {
        return;
    }
    // reached a node that was being visited in the same dfs, it's a cicle
    if (visited[node] == 0) {
        has_cicle = true;
        return;
    }
    visited[node] = 0;  // node is being visited
    for (auto& u : adj[node]) {
        dfs(adj, visited, u, has_cicle);
    }
    visited[node] = 1;  // node is fully visited
}

void bfs(vector<vector<int>>& adj, vector<int>& visited,
         int node, vector<int>& distance, int& max_minutes_spent) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    distance[node] = 1;  // the root node spents 1 minute
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                distance[u] = distance[v] + 1;
                max_minutes_spent = max(max_minutes_spent, distance[u]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m, u;
    vector<vector<int>> adj(MAX_N);
    vector<int> visited(MAX_N), is_root(MAX_N), distance(MAX_N);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            adj[i].clear(), visited[i] = -1, is_root[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> u;
                u -= 1;
                is_root[u] = 0;
                adj[i].push_back(u);
            }
        }
        bool has_cicle = false;
        for (int i = 0; i < n; i++) {
            dfs(adj, visited, i, has_cicle);
        }
        if (has_cicle) {
            cout << "-1\n";
            continue;
        }
        int max_minutes_spent = 1;  // if every node is a root node without dependencies
        fill(visited.begin(), visited.begin() + n, 0);
        for (int i = 0; i < n; i++) {
            if (is_root[i]) {
                bfs(adj, visited, i, distance, max_minutes_spent);
            }
        }
        cout << max_minutes_spent << "\n";
    }

    return 0;
}
