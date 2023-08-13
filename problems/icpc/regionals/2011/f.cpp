#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, a, b, current, ans;
    vector<pair<int, int>> objects(MAX_N);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            objects[i] = {a, b};
        }

        sort(objects.begin(), objects.begin() + n,
             [](const pair<int, int>& p, const pair<int, int>& q) { return p.second < q.second; });

        current = ans = 0;

        for (int i = 0; i < n; i++) {
            if (objects[i].first > current) {
                ans += 1, current = objects[i].second;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
