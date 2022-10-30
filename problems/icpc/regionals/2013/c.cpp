/*
    Solution 1: 0.084s
        DFS Time Complexity: O(V + E)
        Swap Time Complexity: O(1)
    Solution 2: 0.255s
        Floyd-Warshall (Transitive Closure) Time Complexity: O(V^3)
        Lookup Time Complexity: O(V)
        Swap Time Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
const int POSITIVE_INFINITY = 1e3;

int age[MAXN], position[MAXN], parent[MAXN][MAXN];

void floyd_warshall(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (parent[j][i]) {
                for (int k = 1; k <= n; k++) {
                    parent[j][k] |= parent[i][k];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, i, x, y, min_age;
    char action;
    while (cin >> n >> m >> i) {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                parent[j][k] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> age[j], position[j] = j;
        }
        while (m--) {
            cin >> x >> y, parent[x][y] = 1;
        }
        floyd_warshall(n);
        while (i--) {
            cin >> ws >> action;
            if (action == 'T') {
                cin >> x >> y;
                swap(age[position[x]], age[position[y]]);
                swap(position[x], position[y]);
            } else {
                cin >> x, x = position[x], min_age = POSITIVE_INFINITY;
                for (int j = 1; j <= n; j++) {
                    if (parent[position[j]][x] && age[position[j]] < min_age)
                        min_age = age[position[j]];
                }
                if (min_age == POSITIVE_INFINITY) {
                    cout << "*\n";
                } else {
                    cout << min_age << "\n";
                }
            }
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
const int POSITIVE_INFINITY = 1e3;

bool visited[MAXN];
vector<int> adj[MAXN];
int age[MAXN], position[MAXN];

int dfs(int x, int min_age) {
    if (visited[x]) return min_age;
    visited[x] = true;
    for (auto v : adj[x]) {
        min_age = dfs(v, min(age[v], min_age));
    }
    return min_age;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m, i, x, y, min_age;
    char action;
    while (cin >> n >> m >> i) {
        for (int j = 1; j <= n; j++) {
            cin >> age[j], position[j] = j, adj[j].clear();
        }
        while (m--) {
            cin >> x >> y;
            adj[y].push_back(x);
        }
        while (i--) {
            cin >> ws >> action;
            if (action == 'T') {
                cin >> x >> y;
                swap(age[position[x]], age[position[y]]);
                swap(position[x], position[y]);
            } else {
                cin >> x;
                for (int j = 1; j <= n; j++) {
                    visited[j] = false;
                }
                min_age = dfs(position[x], POSITIVE_INFINITY);
                if (min_age == POSITIVE_INFINITY) {
                    cout << "*\n";
                } else {
                    cout << min_age << "\n";
                }
            }
        }
    }
    return 0;
}
*/
