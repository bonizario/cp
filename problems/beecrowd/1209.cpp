#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, int k, vector<int>& friends) {
    if (visited[node] || friends[node] >= k) {
        return;
    }
    visited[node] = true;
    for (auto& u : adj[node]) {
        friends[u]--;
        if (friends[u] < k) {
            dfs(adj, visited, u, k, friends);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    // freopen("1209.in", "r", stdin);
    // freopen("1209.myout", "w", stdout);

    int n, m, k, a, b;
    vector<vector<int>> adj(MAX_N);
    vector<int> friends(MAX_N), visited(MAX_N), invited(MAX_N);

    while (cin >> n >> m >> k) {
        for (int i = 0; i < n; i++) {
            adj[i].clear(), friends[i] = 0, visited[i] = false;
        }
        while (m--) {
            cin >> a >> b;
            friends[--a] += 1, friends[--b] += 1;
            adj[a].push_back(b), adj[b].push_back(a);
        }
        for (int i = 0; i < n; i++) {
            dfs(adj, visited, i, k, friends);
        }
        int total_invited = 0;
        for (int i = 0; i < n; i++) {
            if (friends[i] >= k) {
                invited[total_invited++] = i + 1;
            }
        }
        if (total_invited == 0) {
            cout << "0\n";
            continue;
        }
        sort(invited.begin(), invited.begin() + total_invited);
        for (int i = 0; i < total_invited - 1; i++) {
            cout << invited[i] << " ";
        }
        cout << invited[total_invited - 1] << "\n";
    }

    return 0;
}
