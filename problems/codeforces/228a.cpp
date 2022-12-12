#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    set<int> s;
    int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        s.insert(n);
    }
    cout << 4 - s.size() << "\n";
    return 0;
}
