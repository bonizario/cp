#include <bits/stdc++.h>
using namespace std;

double calc_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2));
}

int find(vector<int>& G, int a) {
    if (a == G[a]) {
        return a;
    }
    return G[a] = find(G, G[a]);
}

void unify(vector<int>& G, vector<int>& S, int a, int b) {
    a = find(G, a), b = find(G, b);
    if (S[a] >= S[b]) {
        G[b] = a;
        S[a] += S[b];
    } else {
        G[a] = b;
        S[b] += S[a];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int m, n, k, x, y, range;
    cin >> m >> n >> k;
    vector<vector<double>> distances(k + 4, vector<double>(k + 4));
    vector<vector<int>> sensors(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> range;
        sensors[i][0] = x, sensors[i][1] = y, sensors[i][2] = range;
    }

    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            distances[i][j] = calc_distance(sensors[i][0], sensors[i][1], sensors[j][0], sensors[j][1]);
        }
    }
    for (int i = 0; i < k; i++) {
        distances[i][k] = calc_distance(sensors[i][0], sensors[i][1], 0, sensors[i][1]);      // LEFT
        distances[i][k + 1] = calc_distance(sensors[i][0], sensors[i][1], m, sensors[i][1]);  // RIGHT
        distances[i][k + 2] = calc_distance(sensors[i][0], sensors[i][1], sensors[i][0], n);  // TOP
        distances[i][k + 3] = calc_distance(sensors[i][0], sensors[i][1], sensors[i][0], 0);  // BOTTOM
    }

    // DEBUG
    // cout << "DISTANCES\n";
    // for (int i = 0; i < k + 4; i++) {
    //     for (int j = 0; j < k + 4; j++) {
    //         cout << distances[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "END\n";

    vector<int> G(k + 4), S(k + 4);
    for (int i = 0; i < k + 4; i++) {
        G[i] = i, S[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        if (distances[i][k] <= sensors[i][2]) {
            unify(G, S, i, k);
        }
        if (distances[i][k + 1] <= sensors[i][2]) {
            unify(G, S, i, k + 1);
        }
        if (distances[i][k + 2] <= sensors[i][2]) {
            unify(G, S, i, k + 2);
        }
        if (distances[i][k + 3] <= sensors[i][2]) {
            unify(G, S, i, k + 3);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (distances[i][j] <= (sensors[i][2] + sensors[j][2])) {
                unify(G, S, i, j);
            }
        }
    }

    bool possible = true;
    if (find(G, G[k]) == find(G, G[k + 1]) ||      // LEFT  <-> RIGHT
        find(G, G[k + 2]) == find(G, G[k + 3]) ||  // TOP   <-> BOTTOM
        find(G, G[k]) == find(G, G[k + 3]) ||      // LEFT  <-> BOTTOM
        find(G, G[k + 1]) == find(G, G[k + 2])) {  // RIGHT <-> TOP
        possible = false;
    }

    cout << (possible ? "S\n" : "N\n");

    return 0;
}
