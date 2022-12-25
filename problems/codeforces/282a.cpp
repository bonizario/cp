#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, ans = 0;
    string statement;
    cin >> n;
    while (n--) {
        cin >> statement;
        if (statement[0] == '+' || statement[2] == '+') {
            ans++;
        } else if (statement[0] == '-' || statement[2] == '-') {
            ans--;
        }
    }
    cout << ans << "\n";
    return 0;
}
