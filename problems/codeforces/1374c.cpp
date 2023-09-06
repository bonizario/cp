#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int ans = 0, curr = 0;
        for (auto& c : s) {
            curr += (c == ')' ? -1 : 1);
            ans = min(ans, curr);
        }
        cout << -ans << "\n";
    }

    return 0;
}
