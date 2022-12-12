#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, num, curr, ans = 0;
    cin >> n;
    while (n--) {
        curr = 0;
        for (int i = 0; i < 3; i++) {
            cin >> num;
            curr += num;
        }
        ans += (curr >= 2 ? 1 : 0);
    }
    cout << ans << "\n";
    return 0;
}
