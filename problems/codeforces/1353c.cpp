#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ull ans = 0, layer = 0;
        for (int i = 1; i <= n / 2; i++) {
            layer += 8;
            ans += (layer * i);
        }
        cout << ans << "\n";
    }

    return 0;
}
