#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = 9999999;

int get_min_blocks(vector<int>& lengths, int n, int m) {
    vector<int> dp(m + 1, MAX_INT);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int k = lengths[i];
        for (int j = k; j <= m; j++) {
            dp[j] = min(dp[j], dp[j - k] + 1);
        }
    }
    return dp[m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    // freopen("in", "r", stdin);
    // freopen("myout", "w", stdout);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> lengths(n);
        for (int i = 0; i < n; i++) {
            cin >> lengths[i];
        }
        sort(lengths.begin(), lengths.end());
        cout << get_min_blocks(lengths, n, m) << "\n";
    }
    return 0;
}
