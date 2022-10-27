/*
    Count how many swaps are required to transform an array into another array.
    Low constraints (2 <= N <= 24)
    Time Complexity: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;

int countSwaps(vector<int>& arr, int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swaps++, swap(arr[j], arr[j + 1]);
            }
        }
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> s(n), f(n), x(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == f[j]) {
                    x[j] = i + 25;
                    // 3  1  2  5  4
                    // 5  3  2  1  4
                    // transforms into
                    // 28 25 27 26 29
                    // just count swaps
                }
            }
        }
        cout << countSwaps(x, n) << "\n";
    }
    return 0;
}
