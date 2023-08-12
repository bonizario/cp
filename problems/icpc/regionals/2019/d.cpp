#include <bits/stdc++.h>
using namespace std;

void dfs_ranks(vector<vector<int>>& inverse_adj, int node, vector<bool>& visited, unordered_map<int, int>& rank) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    if (node == 1) {
        rank[node] = 1;
    }
    for (auto u : inverse_adj[node]) {
        rank[u] = rank[node] + 1;
        dfs_ranks(inverse_adj, u, visited, rank);
    }
}

void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited, int& current_seen) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    current_seen += 1;
    for (auto u : adj[node]) {
        dfs(adj, u, visited, current_seen);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    // freopen("e.in", "r", stdin);
    // freopen("e.myout", "w", stdout);

    int n, k, superior;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> inverse_adj(n + 1);
    unordered_map<int, bool> is_leaf;
    unordered_map<int, int> rank;

    for (int i = 1; i <= n; i++) {
        is_leaf[i] = true;
    }
    rank[1] = 1;
    for (int i = 1; i < n; i++) {
        cin >> superior;
        adj[i + 1].push_back(superior);
        inverse_adj[superior].push_back(i + 1);
        is_leaf[superior] = false;
    }

    vector<bool> visited(n + 1, false);
    dfs_ranks(inverse_adj, 1, visited, rank);

    vector<pair<int, int>> leaves;  // {rank, node_index}
    for (int i = 1; i <= n; i++) {
        if (is_leaf[i]) {
            leaves.push_back({rank[i], i});
        }
        visited[i] = false;
    }

    sort(leaves.begin(), leaves.end(), greater<pair<int, int>>());

    // DEBUG
    // for (int i = 0; i < (int)leaves.size(); i++) {
    //     cout << "rank=" << leaves[i].first << " i=" << leaves[i].second << "\n";
    // }

    vector<pair<int, int>> seen_with_dfs;

    for (auto [r, i] : leaves) {
        int current_seen = 0;
        dfs(adj, i, visited, current_seen);
        seen_with_dfs.push_back({current_seen, i});
    }

    sort(seen_with_dfs.begin(), seen_with_dfs.end(), greater<pair<int, int>>());

    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += seen_with_dfs[i].first;
    }
    cout << ans << "\n";

    return 0;
}
