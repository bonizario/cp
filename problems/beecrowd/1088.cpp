#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &bit, int n, int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int getSum(vector<int> &bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void convert(vector<int> &arr, int n) {
    // convert {7, -90, 100, 1} to {3, 1, 4, 2}
    vector<int> temp(arr);
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
    }
}

int countSwaps(vector<int> &arr, int n) {
    int swaps = 0;
    convert(arr, n);
    vector<int> bit(n + 1);
    fill(bit.begin(), bit.end(), 0);
    for (int i = n - 1; i >= 0; i--) {
        // get count of elements smaller than arr[i]
        swaps += getSum(bit, arr[i] - 1);
        // add current element to BIT
        update(bit, n, arr[i], 1);
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n && n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (countSwaps(arr, n) & 1) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }
    return 0;
}

// {3, 1, 4, _2}
// [0, 0, 0, 0]
// swaps += 0
// [0, 1, 1, 1]

// {3, 1, _4, 2}
// [0, 1, 1, 1]
// swaps += 1
// [0, 1, 1, 2]

// {3, _1, 4, 2}
// [0, 1, 1, 2]
// swaps += 0
// [1, 2, 2, 3]

// {_3, 1, 4, 2}
// [1, 2, 2, 3]
// swaps += 2
// [1, 2, 3, 4]

// {3, 1, 4, 2}
// {1, 3, 4, 2}
// {1, 3, 2, 4}
// {1, 2, 3, 4}
