#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

void update(vector<int> &bit, int n, int idx, int val, bool multiply) {
    if (multiply) {
        while (idx <= n) {
            bit[idx] *= val;
            idx += (idx & -idx);
        }
    } else {
        while (idx <= n) {
            bit[idx] /= val;
            idx += (idx & -idx);
        }
    }
}

int getProduct(vector<int> &bit, int idx) {
    int product = 0;
    while (idx > 0) {
        product *= bit[idx];
        idx -= (idx & -idx);
    }
    return product;
}

int getSum(vector<int> &bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main() {
    char command;
    int n, k, a, b;
    vector<int> bit(MAXN), bitzeros(MAXN), freq(MAXN);
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            bit[i] = 1, bitzeros[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> freq[i];
            if (freq[i]) {
                update(bit, n, i, freq[i], true);
            } else {
                update(bitzeros, n, i, 1, true);
            }
        }
        while (k--) {
            cin >> command;
            cin >> a >> b;
            // 1 3 0 4 6
            // 5 na posição 3
            //

            if (command == 'C') {
                int old = freq[a];
                freq[a] += b;
                if (old == 0 && freq[a] == 0) {
                    continue;
                } else if (old == 0 && freq[a]) {
                    update(bit, n, a, freq[a], true);
                } else if (old && freq[a] == 0) {
                    update(bit, n, a, old, false);
                } else {
                    update(bit, n, a, old, false);
                    update(bit, n, a, freq[a], true);
                }
            } else {
                // CHECK FOR ZEROS WITH BITZEROS - GETSUM
                int product = getProduct(bit, b) / getProduct(bit, a);
                if (product > 0) {
                    cout << "+";
                } else if (product < 0) {
                    cout << "-";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
