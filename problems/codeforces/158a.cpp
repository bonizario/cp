#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a;
        if (a == 0) {
            cout << i << "\n";
            return 0;
        }
    }
    for (int i = k; i < n; i++) {
        cin >> b;
        if (b != a) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}
