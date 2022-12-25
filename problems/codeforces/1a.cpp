#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long n, m, a;
    cin >> n >> m >> a;
    long long horizontal = (n % a == 0 ? n / a : n / a + 1);
    long long vertical = (m % a == 0 ? m / a : m / a + 1);
    cout << horizontal * vertical << "\n";
    return 0;
}
