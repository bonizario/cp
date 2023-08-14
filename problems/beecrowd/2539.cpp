// Adaptation of 1088
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1e5;

void update(vector<ll>& bit, ll n, ll idx, ll val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

ll getSum(vector<ll>& bit, ll idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

ll countSwaps(vector<ll>& arr, vector<ll>& bit, ll n) {
    ll swaps = 0;
    fill(bit.begin(), bit.begin() + n + 1, 0);
    for (ll i = n - 1; i >= 0; i--) {
        swaps += getSum(bit, arr[i] - 1);
        update(bit, n, arr[i], 1);
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, sn;
    vector<ll> arr(MAX_N), bit(MAX_N + 1);
    while (cin >> n) {
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sn = n * (n - 1) / 2;
        cout << sn - countSwaps(arr, bit, n) << "\n";
    }

    return 0;
}
