#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, r, x;
    while (cin >> n >> r) {
        if (n == r) {
            while (r--) cin >> x;
            cout << "*\n";
            continue;
        }
        vector<bool> alive(n + 1);
        while (r--) cin >> x, alive[x] = true;
        for (int i = 1; i <= n; i++)
            if (!alive[i]) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
