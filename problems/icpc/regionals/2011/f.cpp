#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, a, b, ans;
    vector<pair<int, int>>::iterator it;
    while (cin >> n) {
        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            intervals[i] = make_pair(b, a);
        }
        sort(intervals.begin(), intervals.end());
        ans = 0, it = intervals.begin();
        while (it != intervals.end()) {
            ans++;
            int current_end = it->first;
            while (it != intervals.end() && it->second <= current_end)
                it++;
        }
        cout << ans << "\n";
    }
    return 0;
}
