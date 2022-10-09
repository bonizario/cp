#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    string a, b;
    unordered_map<string, string> dict;
    cin >> n >> m;
    while (m--) cin >> a >> b, dict[a] = b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i) cout << " ";
        if (a.size() <= dict[a].size())
            cout << a;
        else
            cout << dict[a];
    }
    cout << "\n";
    return 0;
}
