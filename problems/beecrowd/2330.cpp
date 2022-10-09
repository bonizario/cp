#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, l, duration;
    cin >> n >> l;
    vector<int> calls(n);
    pair<int, int> seller;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(0, i));
    }
    while (l--) {
        cin >> duration;
        seller = pq.top();
        pq.pop();
        seller.first += duration;
        pq.push(seller);
        calls[seller.second]++;
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << calls[i] << "\n";
    }
    return 0;
}
