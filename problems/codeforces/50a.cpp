#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << n * m / 2 << "\n";
    // int vertical, horizontal;
    // int vertical_alignment = 0;
    // vertical = n / 2, horizontal = m;
    // if (vertical && horizontal) {
    //     vertical_alignment = vertical * horizontal;
    //     vertical_alignment += ((n - 2 * vertical) * (horizontal / 2));
    // }
    // int horizontal_alignment = 0;
    // vertical = n, horizontal = m / 2;
    // if (vertical && horizontal) {
    //     horizontal_alignment = vertical * horizontal;
    //     horizontal_alignment += ((m - 2 * horizontal) * (vertical / 2));
    // }
    // cout << max(vertical_alignment, horizontal_alignment) << "\n";
    return 0;
}
