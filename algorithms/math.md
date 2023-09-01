### Sieve of Eratosthenes

```py
# We will find all primes in the range 1 to 120
# is_prime[i] = 1 means that i is prime and is_prime[i] = 0 means that i is composite
# Initially, we say all of them are prime
N = 121
is_prime = [1]*N
# We know 0 and 1 are composites
is_prime[0] = 0
is_prime[1] = 0

def sieve():
    """
    We cross out all composites from 2 to sqrt(N)
    """
    i = 2
    # This will loop from 2 to int(sqrt(x))
    while i*i <= N:
        # If we already crossed out this number, then continue
        if is_prime[i] == 0:
            i += 1
            continue

        j = 2*i
        while j < N:
            # Cross out this as it is composite
            is_prime[j] = 0
            # j is incremented by i, because we want to cover all multiples of i
            j += i

        i += 1

sieve()
for i in xrange(1, N):
    if is_prime[i] == 1:
        print i,
# Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113
```

### 1152 (Kruskal's Algorithm)

```cpp
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
```

### 2550 (Kruskal's Algorithm Check if connected)

```cpp
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
```

### 1552 (Kruskal's Algorithm with dots in a 2D plane)

```cpp
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
```
